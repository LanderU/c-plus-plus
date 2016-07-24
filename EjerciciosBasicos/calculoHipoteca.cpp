#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const float TOTAL_HIPOTECA = 50000.00;
const int TOTAL_ANOS = 7;
const float TIPO_INTERES = 0.0524;

int main() {

	int interesMensual = TIPO_INTERES / 12;
	int numeroPagos = TOTAL_ANOS * 12;
	
	float calculo = (TOTAL_HIPOTECA * pow(interesMensual + 1, numeroPagos)* interesMensual)/(pow(interesMensual +1, numeroPagos)-1);

	cout << fixed << setprecision(2) << "Para una cantidad de " << TOTAL_HIPOTECA << " con una tasa de insterés de " << TIPO_INTERES << " y un total de " << TOTAL_ANOS << " años "
	"sus pagos mensuales son de " << calculo << "€." << endl;

	return 0;
}