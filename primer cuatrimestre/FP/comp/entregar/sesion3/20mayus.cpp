/*El programa lee un car�cter (supondremos que el usuario introduce una may�scula),
lo pase a min�scula y lo imprime en pantalla. */
#include<iostream>
#include<cmath>
using namespace std;
int main (){
	char letra ;
	cout << "Introduce una letra may�scula: " ;
	cin >> letra ;
	letra = letra + 32 ; //Las letras mayusculas tienen valores de 65 a 90 y las min�sculas de 97 a 122
	/* como la distancia entre cualquier letra may�scula y su min�scula es 32. Basta con sumar 32 a un
	un dato que contenta el valor de una letra may�scula para transformarla a min�scula. */
	cout << letra ;
}//Por Francisco Navarro Morales grg121@correo.ugr.es
