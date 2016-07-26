#include <iostream>
#include <iomanip>

using namespace std;

int main () {

	int partNumber;
	int quantity;
	float unitPrice;
	float totalPrice;

	cout << fixed << showpoint << setprecision(2);

	cout << "Introduzca el número de la parte: ";
	cin >> partNumber;

	cout << "Introduzca la cantidad pedida de esa parte: ";
	cin >> quantity;

	cout << "Introduzca el precio unitario: ";
	cin >> unitPrice;

	totalPrice = quantity * unitPrice;

	cout << "El total es: " << totalPrice << endl;
		

	return 0;
}