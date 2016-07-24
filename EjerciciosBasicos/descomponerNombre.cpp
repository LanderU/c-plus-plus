#include <iostream>
#include <string>

using namespace std;

const string FULL_NAME="Lander Usategui San Juan";

int main() {

	string firstName = FULL_NAME.substr(0,6);
	string secondName = FULL_NAME.substr(7,8);
	string lastName = FULL_NAME.substr(16, FULL_NAME.length());

	cout << "El nombre completo es: " << FULL_NAME << endl;
	cout << "El nombre es: " << firstName << endl;
	cout << "El primer apellido es: " << secondName << endl;
	cout << "El segundo apellido es: " << lastName << endl;
	cout << "El nombre completo tiene un total de " << FULL_NAME.length() << " caracteres." << endl;

	return 0;
}