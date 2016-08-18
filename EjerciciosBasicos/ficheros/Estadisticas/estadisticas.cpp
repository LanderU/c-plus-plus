#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Declarar prototipos de función
void OpenFiles(ifstream& inData, ofstream& outData);
void InputGrades(int grades[], int& numGrades, ifstream& inData);
float CalculateAverage(int const grades[], int numGrades);
int CalculateHighest(int const grades[]);
int CalculateLowest(int const grades[]);
int CalculateAboveAverage(int const grades[], fl oat average);
int CalculateBelowAverage(int const grades[], fl oat average);
void PrintResults(ofstream& outData, int numGrades, fl oat average,
int highest, int lowest, int aboveAverage, int belowAverage);
int main()
{
	int grades[101]; 
	int numGrades; 
	float average; 
	int highest; 
	int lowest; 
	int aboveAverage; 

	ifstream inData;
	ofstream outData;
	OpenFiles(inData, outData);
	if ( !inData || !outData ){
		cout << "Los archivos no se abrieron con éxito. " << endl;
		return 1;
	}

	InputGrades(grades, numGrades, inData);
	average = CalculateAverage(grades, numGrades);
	highest = CalculateHighest(grades);
	lowest = CalculateLowest(grades);
	aboveAverage = CalculateAboveAverage(grades, average);
	belowAverage = CalculateBelowAverage(grades, average);
	PrintResults(outData, numGrades, average, highest, lowest,
	aboveAverage, belowAverage);
	inData.close();
	outData.close();

	return 0;
}

void OpenFiles(ifstream& text, ofstream& outFile){
	string inFileName;
	string outFileName;
	cout << "Introduzca el nombre del archivo que será procesado" << endl;
	cin >> inFileName;
	text.open(inFileName.c_str());
	cout << "Introduzca el nombre del archivo de salida" << endl;
	cin >> outFileName;
	outFile.open(outFileName.c_str());
	outFile << "Análisis de los exámenes en el archivo " << inFileName << endl << endl;
}

float CalculateAverage(int const grades[], int numGrades ){
	int sum = 0;

	for (int index = 0; index <= 100; index++){
		sum = sum + grades[index] * index;
	}

	return float(sum) / float(numGrades);
}

void InputGrades(int grades[], int& numGrades, ifstream& inData){
	int grade;
	
	for (int index = 0; index <= 100; index++){
		
		grades[index] = 0;
	}
	numGrades = 0;
	
	inData >> grade; 

	while (inData)
	{ 
		grades[grade]++;
		numGrades++;
		inData >> grade;
	}
}

int CalculateHighest(int const grades[]){
	int highGrade = 100;

	while (grades[highGrade] == 0){

		highGrade--;
	}
	
	return highGrade;
}

int CalculateLowest(int const grades[]){
	int lowGrade = 0;

	while (grades[lowGrade] == 0){
		
		lowGrade++;
	}

	return lowGrade;
}

int CalculateAboveAverage(int const grades[], float average) {
	int averagePlus = (int)(average) + 1;
	int index;
	int number = 0;
	for (index = averagePlus; index <= 100; index++){
		
		number = number + grades[index];
	}

	return number;
}

int CalculateBelowAverage(int const grades[], float average){
	int truncatedAverage = (int) (average);
	int index;
	int number = 0;
	for (index = 0; index <= truncatedAverage; index++){

		number = number + grades[index];
	}
		
	return number;
}

void PrintResults(ofstream& outData, int numGrades, float average, int highest, int lowest, int aboveAverage, int belowAverage){

	outData << "El número de calificaciones es " << numGrades << endl;
	outData << fi xed << setprecision(2) << "La calificación promedio es " << average << endl;
	outData << "La califi cación más alta es " << highest << endl;
	outData << "La califi cación mínima es " << lowest << endl;
	outData << "El número de calificaciones arriba del promedio es "<< aboveAverage << endl;
	outData << "El número de calificaciones abajo del promedio es "<< belowAverage << endl;
}