#include <fstream>
#include <string> 

using namespace std;

int main(){

	ifstream datosEntrada;
	ofstream datosSalida;
	datosEntrada.open("nombres");
	datosSalida.open("salidas");

	string numeroSS;
	string nombre;
	string apellido;
	string segundoApellido;
	string inicial;

	datosEntrada >> numeroSS >> nombre >> apellido >> segundoApellido;

	inicial = segundoApellido.substr(0, 1) + '.';

	datosSalida << nombre << ' ' << apellido << ' ' << segundoApellido << ' ' << inicial << ' ' << numeroSS << endl;

	datosEntrada.close();
	datosSalida.close();	

	return 0;
}