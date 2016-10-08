/*
25. El programa realiza distintas operaciones:
1) devuelve true si la letra introducida es minúscula y falso en otro caso
2) devuelve true si la edad introducida es menor de 18 o mayor de 65
3) devuelve true si el año introducido es bisiesto */

#include<iostream>
#include<cmath>
using namespace std;
int main (){
	char letra ;
	int edad, year, cuatro, cien, cuatrocientos ; //cuatro, cien y cuatrocientos servirán para comprobar si se trata o no de un múltiplo.
	cout << "Introduce una letra: " ;
	cin >> letra ;
	cout << "Introduce una edad: " ;
	cin >> edad ;
	cout << "Introduce un año: " ;
	cin >> year ;
	cuatro = year % 4 ;
    cien = year % 100 ;
    cuatrocientos = year % 400 ;
	bool es_minuscula, es_intervalo, es_bisiesto ;
	es_minuscula = (letra > 96) && (letra < 123) ;
	es_intervalo = (edad < 18) || (edad > 65) ;
	es_bisiesto = (cuatro == 0) && !(cien == 0) || (cuatrocientos == 0);/* Hay que tener en cuenta que en este caso se puede poner la expresión
	lógica sin ningún paréntesis porque la prioridad se establece según ! > && > ||, tal y cómo nos interesa. De no ser así, sería necesario el
	uso de paréntesis */

	cout << es_minuscula << es_intervalo << es_bisiesto;
}
