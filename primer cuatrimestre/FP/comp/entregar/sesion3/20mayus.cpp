/*El programa lee un carácter (supondremos que el usuario introduce una mayúscula),
lo pase a minúscula y lo imprime en pantalla. */
#include<iostream>
#include<cmath>
using namespace std;
int main (){
	char letra ;
	cout << "Introduce una letra mayúscula: " ;
	cin >> letra ;
	letra = letra + 32 ; //Las letras mayusculas tienen valores de 65 a 90 y las minúsculas de 97 a 122
	/* como la distancia entre cualquier letra mayúscula y su minúscula es 32. Basta con sumar 32 a un
	un dato que contenta el valor de una letra mayúscula para transformarla a minúscula. */
	cout << letra ;
}//Por Francisco Navarro Morales grg121@correo.ugr.es
