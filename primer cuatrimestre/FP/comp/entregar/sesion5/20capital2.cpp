#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int years;
	double capital_inicial;
	double interes;
    long double total_acumulado;
	double doble_cantidad_inicial;
	cout << " Introduce el capital ingresado " ;
	cin >> capital_inicial ;
	cout << " Introduce el inter�s en cuesti�n (tanto por ciento): " ;
	cin >> interes;
    doble_cantidad_inicial = 2 * capital_inicial ;
    years = 1 ;
    total_acumulado = capital_inicial + capital_inicial * interes/100;
	while (total_acumulado < doble_cantidad_inicial){
	total_acumulado = total_acumulado + total_acumulado * interes/100;
	years++ ;
    }

    cout << "Ser�n necesarios " << years << " a�os para doblar la cantidad inicial. En este tiempo se acumular� un capital de: "  << total_acumulado;
}// Por Francisco Navarro Morales. grg121@correo.ugr.es
