/*
25. El programa realiza distintas operaciones:
1) devuelve true si la letra introducida es min�scula y falso en otro caso
2) devuelve true si la edad introducida es menor de 18 o mayor de 65
3) devuelve true si el a�o introducido es bisiesto */

#include<iostream>
#include<cmath>
using namespace std;
int main (){
	char letra ;
	int edad, year, cuatro, cien, cuatrocientos ; //cuatro, cien y cuatrocientos servir�n para comprobar si se trata o no de un m�ltiplo.
	cout << "Introduce una letra: " ;
	cin >> letra ;
	cout << "Introduce una edad: " ;
	cin >> edad ;
	cout << "Introduce un a�o: " ;
	cin >> year ;
	cuatro = year % 4 ;
    cien = year % 100 ;
    cuatrocientos = year % 400 ;
	bool es_minuscula, es_intervalo, es_bisiesto ;
	es_minuscula = (letra > 96) && (letra < 123) ;
	es_intervalo = (edad < 18) || (edad > 65) ;
	es_bisiesto = (cuatro == 0) && !(cien == 0) || (cuatrocientos == 0);/* Hay que tener en cuenta que en este caso se puede poner la expresi�n
	l�gica sin ning�n par�ntesis porque la prioridad se establece seg�n ! > && > ||, tal y c�mo nos interesa. De no ser as�, ser�a necesario el
	uso de par�ntesis */

	cout << es_minuscula << es_intervalo << es_bisiesto;
}
