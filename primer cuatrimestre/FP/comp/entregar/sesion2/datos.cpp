/*El programa lee un valor entero. Los datos aparecen en pantalla separados por tres espacios en blanco. */
#include<cmath>
#include<iostream>
using namespace std;
int main (){
	int dato, derecha, centro, izquierda, dato_entero;
	cout << "Introduce un valor entero de la forma: \"245\" (hasta un máximo de 3 caracteres)\n" ;
	cin >> dato;
	derecha = dato%10;
	dato_entero = dato/10;
	centro = dato_entero%10;
	izquierda = dato_entero/10; 
	cout << izquierda << "   " << centro << "   " << derecha ; 
}//Por Francisco Navarro Morales - GRG121
