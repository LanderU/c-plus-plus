#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

// Firma de las funciones

void AbrirFicheros(ifstream&, ofstream&);
void Conteo(char, int&, int&, int&, int&, int&);
void ImprimirTabla(ofstream& tabla, int, int, int, int, int);


int main() {

	ifstream texto;
	ofstream tabla;
	char caracter;

	// Contadores
	int mayusculas = 0;
	int minusculas = 0;
	int espacios = 0;
	int signosPuntuacion = 0; // '.', '!', '?'
	int resto = 0;

	AbrirFicheros(texto, tabla);

	if(!texto || !tabla){

		cout << "Alguno de los archivos o ambos no se han podido abrir." << endl;

		return 1;

	}else {

		texto.get(caracter);

		do {

			// Efectuamos la llamada a la función para hacer el conteo
			Conteo(caracter, mayusculas, minusculas, espacios, signosPuntuacion, resto);

			texto.get(caracter);

		}while(texto); // Mientras sigamos teniendo datos que procesar continuamos

		// Llamamos a la función para guardar los datos en el fichero
		ImprimirTabla(tabla, mayusculas, minusculas, espacios, signosPuntuacion, resto);

		cout << "Proceso terminado, vea el archivo para obtener los datos." << endl;

		// Cerramos los flujos
		texto.close();
		tabla.close();
		return 0;
	}// end if

}// end main

// Funciones

void AbrirFicheros(ifstream& texto, ofstream& tabla){

	string archivoEntrada;
	string archivoSalida;

	cout << "Escriba el nombre del archivo: ";
	cin >> archivoEntrada;

	texto.open(archivoEntrada.c_str());

	cout << "Escriba el nombre del fichero de salida: ";
	cin >> archivoSalida;

	tabla.open(archivoSalida.c_str());

	// Introducimos un encabezado.

	tabla << "Análisis de caracteres en el archivo de salida " << archivoSalida << endl;

}// end AbrirFicheros

void Conteo(char caracter, int& mayusculas, int& minusculas, int& espacios, int& signosPuntuacion, int& resto){

	if(isupper (caracter)){
		mayusculas++;
	}else if(islower(caracter)){
		minusculas++;
	}else if(caracter == ' '){
		espacios++;
	}else if((caracter == '.') || (caracter == '?') || (caracter == '!')){
		signosPuntuacion++;
	}else{
		resto++;
	}// end if

}// end Conteo

void ImprimirTabla(ofstream& tabla, int mayusculas, int minusculas, int espacios, int signosPuntuacion, int resto){

	const int MULTIPLICADOR = 100;

	float total = mayusculas + minusculas + espacios + signosPuntuacion + resto;

	// Escribimos los resultados
	tabla << fixed << setprecision(3) << "Porcentaje de mayúsculas: " << (mayusculas/total) * MULTIPLICADOR << endl;
	tabla << fixed << setprecision(3) << "Porcentaje de minusculas: " << (minusculas/total) * MULTIPLICADOR << endl;
	tabla << fixed << setprecision(3) << "Porcentaje de espacios en blanco: " << (espacios/total) * MULTIPLICADOR << endl;
	tabla << fixed << setprecision(3) << "Porcentaje de signos de puntuación: " << (signosPuntuacion/total) * MULTIPLICADOR << endl;
	tabla << fixed << setprecision(3) << "Porcentaje del resto de caracteres: " << (resto/total) * MULTIPLICADOR << endl;

}// end ImprimirTabla