/*El programa entrega el tiempo transcurrido (en segundos) entre dos instantes dados.
El usuario debe introducir  tales instantes separando la hora de los minutos y los 
segundos por un espacio o una barra "/" */
#include<iostream>
#include<cmath>
using namespace std;
int main (){
	int hora_inicial, minutos_inicial, segundos_inicial;
	int hora_final, minutos_final, segundos_final;
	int inicial, final,resultado;
	cout << "Introduzca los datos del instante inicial. Esto es: \"hora/minutos/segundos. \n";
	cin >> hora_inicial >> minutos_inicial >> segundos_inicial; // De esta forma evitamos realizar 3 "cin" y sus 3 "cout"
	cout << "A continuación introduzca, de la misma forma, los datos del instante final. \n" ;
	cin >> hora_final >> minutos_final >> segundos_final; 
	inicial = 3600*hora_inicial + 60*minutos_inicial + segundos_inicial;
	final = 3600*hora_final + 60*minutos_final + segundos_final;
   resultado = final - inicial;
   cout << "Los segundos transcurridos son: " << resultado;
}//Por Francisco Navarro Morales - GRG121
