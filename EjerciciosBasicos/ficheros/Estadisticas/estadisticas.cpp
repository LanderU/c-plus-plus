#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Declaración de funciones.
void AbrirFicheros(ifstream& datosEntrada, ofstream& datosSalida);
//float CalcularMedia(int const calificaciones[], int TOTAL_CALIFICACIONES);
int CalcularMayor(int const calificaciones[], int TOTAL_CALIFICACIONES);
int CalcularMenor(int const calificaciones[], int TOTAL_CALIFICACIONES);
void GuardarResultados(ofstream& datosSalida, int TOTAL_CALIFICACIONES, int mayor, int menor);
void Error();
void Satisfactorio();


int main(){

	// declaraciones
	ifstream datosEntrada;
	ofstream datosSalida;

	AbrirFicheros(datosEntrada, datosSalida);

	if (!datosEntrada || !datosSalida){

		Error();

		return 1;

	}else{

		int contador = 0;
		int trash;
		int calificaciones [101];

		// Inicializamos el array

		for (int i = 0; i <=100; i++){

			calificaciones[i] = 0;

		}// end for

		datosEntrada >> trash;

		while(datosEntrada) {

			calificaciones[trash]++;
			contador++;
			datosEntrada >> trash;

		}/// end while

		//float media;
		int mayor;
		int menor;

		//media = CalcularMedia(calificaciones, TOTAL_CALIFICACIONES);
		mayor = CalcularMayor(calificaciones, TOTAL_CALIFICACIONES);
		menor = CalcularMenor(calificaciones, TOTAL_CALIFICACIONES);
		GuardarResultados(datosSalida, TOTAL_CALIFICACIONES, mayor, menor);
		Satisfactorio();
		datosEntrada.close();
		datosSalida.close();

		return 0;
	}// end if

	
}// end main

// Funciones

void AbrirFicheros(ifstream& datosEntrada, ofstream& datosSalida){

	string inputFile;
	string outputFile;

	cout << "Introduzca el nombre del archivo de donde leer las calificaciones: ";
	cin >> inputFile;
	datosEntrada.open(inputFile.c_str());

	cout << "Introduzca el nombre del fichero en el cual se guardarán las estadísticas: ";
	cin >> outputFile;
	datosSalida.open(outputFile.c_str());
	datosSalida << "Análisis de los exámenes." << endl;


}// end AbrirFicheros


/*
float CalcularMedia(int calificaciones[], int TOTAL_CALIFICACIONES){

	float total = 0;

	for (int i = 0 ; i < TOTAL_CALIFICACIONES; i++){

		total += calificaciones[i];

	}//end for

	return float(total /= TOTAL_CALIFICACIONES);

}// end CalcularMedia
*/

int CalcularMayor(int const calificaciones[], int TOTAL_CALIFICACIONES){

	int mayorNota = 0;

	for (int i = 0; i < TOTAL_CALIFICACIONES; i++){

		/*if (calificaciones[i] > mayorNota){

			mayorNota = calificaciones[i];
		}// en if
		*/

	}// end for

	return mayorNota;

}//end CaluclarMayor

int CalcularMenor(int const calificaciones[], int TOTAL_CALIFICACIONES){

	int menorNota= 99999;

	for(int i = 0; i < TOTAL_CALIFICACIONES; i++){

		if (calificaciones[i] < menorNota){

			menorNota = calificaciones[i];
		}// end if

	}// end for

	return menorNota;

}// end CalcularMenor

void GuardarResultados(ofstream& datosSalida, int TOTAL_CALIFICACIONES, int mayor, int menor){

	datosSalida << "El número total de calificaciones es: " << TOTAL_CALIFICACIONES << endl;
	//datosSalida << "La media de las calif,icaciones es: " << fixed << setprecision(2) << media << endl;
	datosSalida << "La nota mayor es: " << mayor << endl;
	datosSalida << "La nota más baja es: " << menor << endl;


}// end GuardarResultados

void Error(){

	cout << "Error al abrir uno o ambos ficheros." << endl;

}// end error

void Satisfactorio(){

	cout << "El proceso se ha terminado correctamente, revise el fichero con los resultados." << endl;

}// end Satisfactorio