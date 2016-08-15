#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

//Enumeración
enum Tipos {MAYUSCULAS, MINUSCULAS, DIGITO, OTROS, EOS, EOW, IGNORAR};

//Firma funciones
void AbrirFicheros(ifstream&, ofstream&);
Tipos Decodificar(char caracter);
void AuditarCaracter(char, int&, int&, int&, int&, int&, int&);
void CrearTabla(ofstream& tabla, int, int, int, int, int, int);
void Error();
void Stisfactorio();

int main(){

	ifstream texto;
	ofstream tabla;
	char caracter;

	// Contadores
	int mayusculas = 0;
	int minusculas = 0;
	int digitos = 0;
	int palabras = 0;
	int sentencias = 0;
	int ignorado = 0;

	AbrirFicheros(texto, tabla);

	if (!texto || ! tabla){

		Error();

		return 1;
	}else{

		texto.get(caracter);

		do {

			AuditarCaracter(caracter, mayusculas, minusculas, digitos, palabras, sentencias, ignorado);
			texto.get(caracter);

		}while(texto);

		CrearTabla(tabla, mayusculas, minusculas, digitos, palabras, sentencias, ignorado);

		Stisfactorio();
		
		texto.close();
		tabla.close();
		return 0;	
	}

	
}//end main

//Funciones

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

	tabla << "Análisis de caracteres en el archivo de salida: " << archivoSalida << endl;

}// end AbrirFicheros

Tipos Decodificar(char caracter){

	if(isupper(caracter)){

		return MAYUSCULAS;

	}else if(islower(caracter)){

		return MINUSCULAS;

	}else {

		switch (caracter){
			case '.':
			case '!':
			case '?': return EOS;
			case ' ':
			case ',':
			case ';':
			case ':':
			case '\n': return EOW;

		}// end switch

	}// end if

	return IGNORAR;

}//end Decodificar

void AuditarCaracter(char caracter, int& mayusculas, int& minusculas, int& digitos, int& palabras, int& sentencias, int& ignorado){

	static bool finPalabra = false;

	switch (Decodificar(caracter)){

		case MAYUSCULAS: mayusculas++;
						 finPalabra = false;
						 break;
		case MINUSCULAS: minusculas++;
						 finPalabra = false;
						 break;
		case DIGITO: digitos++;
					 finPalabra = false;
					 break;
		case EOW: if(!finPalabra){
						palabras++;
						finPalabra = true;
					}// end if
				   break;
		case EOS: sentencias++;
				  break;
		case IGNORAR: ignorado++;
					  break;
	}//end switch

}//end AuditarCaracter

void CrearTabla (ofstream& tabla, int mayusculas, int minusculas, int digitos, int palabras, int sentencias, int ignorado){

	int totalAlphaNumerico = mayusculas + minusculas + digitos;

	// Guardamos los datos en el archivo.

	tabla << "Estos son los resultados que se han obtenido: " << endl;
	tabla << "Número de caracteres alfanuméricos: " << totalAlphaNumerico << endl;
	tabla << "Número total de caracteres en mayúsculas: " << mayusculas << endl;
	tabla << "Número total de caracteres en minúsculas: " << minusculas << endl;
	tabla << "Número total de dígitos: " << digitos << endl;
	tabla << "Número total de ignorados: " << ignorado << endl;

	palabras += sentencias;

	tabla << "Número total de palabras: " << palabras << endl;
	tabla << "Número de sentencias: " << sentencias << endl;
	tabla << "Promedio de longitud de palabra: " << fixed << setprecision(3) << float(totalAlphaNumerico) / palabras << endl;
	tabla << "Promedio longitud de sentencia: " << fixed << setprecision(3) << float(palabras) / sentencias << endl;

}//end CrearTabla

void Error(){

	cout << "Uno de los dos archivos o ambos no pueden abrirse." << endl;

}//end Error

void Stisfactorio(){

	cout << "Proceso realizado con exito, compruebe el arvhivo de salida para comprobar los datos" << endl;

}//end Satisfactorio