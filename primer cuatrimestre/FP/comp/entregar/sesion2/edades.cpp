/* El programa intencambia el contenido de dos variables enteras. Lee desde el teclado las variables edad_Pedro y 
edad_Juan e intercambia sus valores. Finalmente muestra en pantalla las variables ya modificadas */
#include<iostream>
#include<cmath>
using namespace std;
int main (){
	int edad_Pedro, edad_Juan, temporal; //la variable temporal soluciona el error que comentamos a continuaci�n.
	cout << "Introduce las edades de Pedro y Juan, separadas por un espacio.\n";
	cin >> edad_Pedro >> edad_Juan;
	/*El c�digo:
	edad_Pedro = edad_Juan
	edad_Juan = edad_Pedro 
	no funcionar�a porque el programa primero evalua la expresi�n de la derecha y despu�s la asigna al dato de la izquierda,
	esto significa que otorgar� el valor de edad_Juan a edad_Pedro, pero entonces otorgar� ese mismo valor a edad_Juan. Es decir,
	que finalmente edad_Juan tendr� el mismo valor que al principio en lugar de tomar el valor de edad_Pedro */
	temporal = edad_Pedro; // conseguimos que "temporal" almacene el valor de edad_Pedro
	edad_Pedro = edad_Juan; //Al otorgar a edad_Pedro el valor de edad_Juan, se pierde su valor, por eso lo hemos almacenado previamente.
	edad_Juan = temporal; // Gracias a "temporal" recuperamos el valor de edad_Pedro.
	cout << "La edad de Pedro es: " << edad_Pedro << " Y la de Juan: " << edad_Juan;
}//Por Francisco Navarro Morales - GRG121
