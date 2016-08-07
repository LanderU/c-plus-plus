#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Firma de las funciones

string DatosPaciente();
void NivelColesterol (ofstream& perfilSalud);
void NivelIMC(ofstream& perfilSalud);
void NivelPresionSanguinea(ofstream& perfilSalud);
void Error();
void Mensaje();

int main(){

	ofstream historial;

	historial.open("historiales");

	if(!historial){

		// Llamada a la función error
		Error();

		return 1;

	}else{

		// Guardamos el nombre y apellido del paciente en el archivo historiales

		historial << "Datos del paciente: " << DatosPaciente() << endl;

		// Llamadas a las funciones para guardar los datos con las evaluaciones.

		NivelColesterol(historial);
		NivelIMC(historial);
		NivelPresionSanguinea(historial);
		Mensaje();

		historial.close();
		return 0;

	}// end if

}// end main

/*
	Funciones
*/

string DatosPaciente() {

	string nombre, apellido;
	cout << "Nombre del paciente: ";
	getline(cin, nombre);
	cout << "Apellidos del paciente: ";
	getline(cin, apellido);

	return nombre + " "+ apellido;

}// end DatosPaciente

void NivelColesterol(ofstream& historial){

	int HDL;
	int LDL;
	float relacion;

	cout << "Introduzca el valor para HDL: ";
	cin >> HDL;
	cout << "Introduzca el valor para LDL: ";
	cin >> LDL;

	relacion = LDL/HDL;

	historial << "Datos relativos al nivel de colesterol:" << endl;
	// Comprobación HDL
	if (HDL < 40){

		historial << "	HDL es demadiado bajo." << endl;

	}else if(HDL < 60){

		historial << "	HDL es correcto." << endl;

	}else {

		historial << "	HDL es excelente." << endl;

	}//end if

	// Comprobación LDL
	if (LDL < 100){

		historial << "	LDL es óptimo." << endl;

	}else if(LDL < 130){

		historial << "	LDL es casi óptimo." << endl;

	}else if(LDL < 160){

		historial << "	LDL estás en el limite." << endl;

	}else if(LDL < 190){

		historial << "	LDL demasiado alto." << endl;

	}else {

		historial << "	LDL es demasiado bajo." << endl;
	}//end if

	// Comprobación relacion LDL/HDL
	if (relacion < 3.22) {

		historial << "	La relación entre LDL con HDL es buena." << endl;

	}else{

		historial << "	La relación entre LDL con HDL no es buena." << endl;

	}// end if


}//end NivelColesterol

void NivelIMC(ofstream& historial){

	const int MULTIPLICADOR = 703;
	float peso;
	float altura;
	float IMC;

	cout << "Introduzca el peso del paciente: ";
	cin >> peso;
	cout << "Introduzca la altura del paciente: ";
	cin >> altura;

	IMC = peso*MULTIPLICADOR/(pow(altura,2));

	historial << "	El índice de masa corporal es: " << IMC << endl;
	historial << "	Interpretación del IMC." << endl;

	// Evaluación de los datos

	if (IMC < 20){

		historial << "	El IMC es muy bajo." << endl;

	}else if(IMC <= 25){

		historial << "	El IMC es correcto." << endl;

	}else if(IMC <= 30){

		historial << "	El IMC es alto." << endl;

	}else {

		historial << "	El IMC es altísimo." << endl;

	}// end if


}// end NivelBMI

void NivelPresionSanguinea(ofstream& historial){

	int systolic;
	int diastolic;

	cout << "Introduzca la tensión arterial sistólitica: ";
	cin >> systolic;
	cout << "Introduzca la tensión arterial diastólica: ";
	cin >> diastolic;

	historial << "Perfil para la tensión arterial." << endl;

	// Evaluación de los datos para systolic.

	if(systolic < 120){

		historial << "	La lecura sístolica es optima." << endl;

	}else if(systolic < 130){

		historial << "	La lectura sístolica es normal." << endl;

	}else if(systolic < 140){

		historial << "	La lectura sístolica es algo alta." << endl;

	}else if(systolic < 160){

		historial << "	La lectura sistólitica indica etapa 1 de hipertensión." << endl;

	}else if(systolic < 180) {

		historial << "	La lectura sistólitica indica etapa 2 de hipertensión." << endl;

	}else {

		historial << "	La lectura sistólitica indica etapa 3 de hipertensión." << endl;

	}//end if

	// Evaluación de los datos para diastolic.

	if(diastolic < 80){

		historial << "	La lectura diastólica es óptima." << endl;

	}else if(diastolic < 85){

		historial << "	La lectura diastólica es normal." << endl;

	}else if(diastolic < 90){

		historial << "	La lectura diastólica es algo alta." << endl;

	}else if(diastolic < 100){

		historial << "	La lectura diastólica indica etapa 1 de hipertensión." << endl;

	}else if(diastolic < 110){

		historial << "	La lectura diastólica indica etapa 2 de hipertensión." << endl;

	}else{

		historial << "	La lectura diastólica indica etapa 3 de hipertensión." << endl;

	}//end if


}//end NivelPresionSanguinea

void Error(){

	cout << "No se puede abrir el archivo, historiales" << endl;

}//end error

void Mensaje(){

	cout << "Los datos se han registrado satisfactoriamente en el archivo historiales, consultelo." << endl;

}// end Mensaje

