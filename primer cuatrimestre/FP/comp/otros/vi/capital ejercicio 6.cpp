#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double capital_inicial;
	double interes;
	double total_acumulado;
	int total_years;
	int contador;
	int year_number;
	double cantidad_final_acumulada;
	cout << " Introduce el capital ingresado " ;
	cin >> capital_inicial ;
	cout << " Introduce el inter�s en cuesti�n " ;
	cin >> interes;
	cout << " Introduce el n�mero de a�os a calcular: ";
	cin >> total_years;
	contador = total_years
    year_number = 2;
    cout << "\nEl valor total acumulado el a�o numero 1 es de: " << total_acumulado;
    cantidad_final_acumulada = total_acumulado;
	while (contador != 0 ){
	total_acumulado = total_acumulado + total_acumulado * interes/100;
	cout << "\nEl valor total acumulado el ao numero " << year_number " << total_acumulado << "\n";
	cantidad_final_acumulada = cantidad_final_acumulada + total_acumulado;
	contador-- ;
	a�o_numero++ ;
    }

}
