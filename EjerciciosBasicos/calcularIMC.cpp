#include <iostream>
#include <cmath>

using namespace std;

int main() {

	float peso;
	float altura;
	float imc;
	const int MULTIPLICADOR = 703;

	cout << "Introduzca su peso: ";
	cin >> peso;

	cout << "Introduzca su altura: ";
	cin >> altura;

	if (altura <= 0.0 || peso <= 0.0){

		cout << "Valores incorrectos" << endl;

		return 1;
	}else{

		imc = peso*MULTIPLICADOR/(pow(altura,2));

		cout << "El calculo de su IMC es: " << imc << endl;

		if (imc < 20) {

			cout << "estás un poco raquitico." << endl;
		}else if (imc <= 25){

			cout << "Correcto." <<endl;

		}else if( imc <= 30){

			cout << "Usted sufre sobrepeso." << endl;
		}else{

			cout << "Vaya al médico." << endl; 

		}

		return 0;		
	}//end if



}//end main