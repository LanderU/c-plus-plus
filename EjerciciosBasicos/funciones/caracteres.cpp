# include <iostream>
# include <cctype>

using namespace std;

// Firmas de las funciones.

void Conteo(char, int&, int&, int&, int&);
void MostradResutados(int, int, int, int);

int main () {

	char charIntroducido [1000];
	int contador = 0;
	int numLetras = 0;
	int numPuntos = 0;
	int numExclamacion = 0;
	int numInterrogacion = 0;

	cout << "Introduzca el texto a evaluar(sin espacios): ";
	cin >> charIntroducido;

	while (charIntroducido[contador] != '\0'){

		Conteo(charIntroducido[contador], numLetras, numPuntos, numInterrogacion, numExclamacion);

		contador++;

	}

	MostradResutados(numPuntos, numLetras, numInterrogacion, numExclamacion);


	return 0;
}

// Funciones.

void Conteo(char caracter, int& numLetras, int& numPuntos, int& numInterrogacion, int& numExclamacion){

	if(isalpha(caracter)){

		numLetras++;

	}else {

		switch (caracter){
			case '.': numPuntos++;
					  break;
			case '?': numInterrogacion++;
				      break;
			case '!': numExclamacion++;
					  break;
			default : ;
		}// end switch

	}// end if

}// end Conteo

void MostradResutados(int numPuntos, int numLetras, int numInterrogacion, int numExclamacion) {

	cout << "El número total de letras es: " << numLetras << endl;
	cout << "El número de caracteres \'.\' es: " << numPuntos << endl;
	cout << "El número total de caracteres \'!\' es: " << numInterrogacion << endl;
	cout << "El número total de caracteres \'?\' es: " << numInterrogacion << endl;

}// end MostrarResultados