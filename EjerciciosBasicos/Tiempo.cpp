#include "Tiempo.h"
#include <iotream>

using namespace std;

int main()
{
	Time time1(5, 30, 0); // Instancia a la clase, constructor con parámetros
	Time time2; // Contructor por omisión
	int loopCount;

	cout << "time1: ";
	time1.Write();
	cout << " time2: ";
	time2.Write();
	cout << endl;

	if (time1.Equal(time2)){
		cout << "Los tiempos son iguales" << endl;
	}else{
		cout << "Los tiempos NO son iguales" << endl;

	}// end if

	time2 = time1;
	cout << "time1: ";
	time1.Write();
	cout << " time2: ";
	time2.Write();
	cout << endl;
	if (time1.Equal(time2)){
		cout << "Los tiempos son iguales" << endl;
	}else{
	cout << "Los tiempos NO son iguales" << endl;
	} //end if

	time2.Increment();
	cout << "Nuevo time2: ";
	time2.Write();
	cout << endl;

	if (time1.LessThan(time2)){
		cout << "time1 es menor que time2" << endl;
	}else{
		cout << "time1 NO es menor que time2" << endl;
	}// end if

	if (time2.LessThan(time1)){
		cout << "time2 es menor que time1" << endl;
	}else{
		cout << "time2 NO es menor que time1" << endl;
	}// end if

	time1.Set(23, 59, 55);
	cout << "Incrementar time1 desde 23:59:55:" << endl;

	for (loopCount = 1; loopCount <= 10; loopCount++)
	{
		time1.Write();
		cout << ' ';
		time1.Increment();
	}// end for

	cout << endl;
	return 0;
}// end main