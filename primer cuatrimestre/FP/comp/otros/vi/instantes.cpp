#include<iostream>
#include<cmath>
using namespace std;
int main (){
	int hora_inicial, minutos_inicial, segundos_inicial;
	int hora_final, minutos_final, segundos_final;
	int inicial, final,resultado;
	cout << "Introduzca los datos del instante inicial. Esto es: \"hora/minutos/segundos. \n";
	cin >> hora_inicial >> minutos_inicial >> segundos_inicial;
	cout << "A continuación introduzca, de la misma forma, los datos del instante final. \n" ;
	cin >> hora_final >> minutos_final >> segundos_final; 
	inicial = 24*hora_inicial + 60*minutos_inicial + segundos_inicial;
	final = 24*hora_final + 60*minutos_final + segundos_final;
   resultado = final - inicial;
   cout << "Los segundos transcurridos son: " << resultado;
}
