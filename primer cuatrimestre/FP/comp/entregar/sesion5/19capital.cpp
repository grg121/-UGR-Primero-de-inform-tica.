#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double capital_inicial;
	int tope_interes;
    long double total_acumulado;
	int tope_year;
	cout << "Introduce el capital ingresado inicialmente: \n" ;
	cin >> capital_inicial ;
	cout << "A continuaci�n se requiere el inter�s maximo a calcular.\nDebe ser un n�mero entero. \n"
         << "Introduce el inter�s m�ximo: " ;
	cin >> tope_interes;
	cout << "Introduce el n�mero de a�os a calcular: \n";
	cin >> tope_year;


	for (int interes = 1 ; interes <= tope_interes ; interes++){

        total_acumulado = capital_inicial ;
        cout << "Calculos realizados al " << interes << "%:" << endl;
        for (int year = 1 ; year <= tope_year ; year++){
            total_acumulado = total_acumulado + total_acumulado * interes / 100;
            cout << "Dinero obtenido el a�o numero " << year << ": " << total_acumulado << endl;
        }
    }

}
