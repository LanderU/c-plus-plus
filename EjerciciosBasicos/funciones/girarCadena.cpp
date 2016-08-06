#include <iostream>
#include <string>

using namespace std;

string darVuelta(string);

int main() {

	string dato;

	cout << "Introduzca una cadena: ";
	getline(cin, dato);
	cout << darVuelta(dato) << endl;

	return 0;
}

string darVuelta(string cadena) {

	string salida;

	for (int i = cadena.size() -1 ; i>= 0 ; i--){

		salida += cadena.at(i);
	}
            	
   	return salida;

}//end darVuelta