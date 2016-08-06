#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

	ifstream notasLeidas;
	notasLeidas.open("notas");

	if (!notasLeidas){

		cout << "No se puede abrir el archivo." << endl;

		return 1;

	}else {
		int contador = 0;
		int totalNotas = 0;
		int tmp;
		float promedio;

		while(!notasLeidas.eof()){

			notasLeidas >> tmp;
			totalNotas = totalNotas + tmp;
			contador++;

		}// end while

		promedio = totalNotas/contador;

		cout << "El promedio de la clase es: " << fixed << setprecision(2) << promedio << endl;

		notasLeidas.close();

		return 0;

	} //end if

} //end main