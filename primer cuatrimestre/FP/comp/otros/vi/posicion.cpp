 /*Construid un programa para calcular la posici�n de un objeto que sigue un movimiento rectil�neo uniforme.
  La posici�n se calcula aplicando la siguiente f�rmula:
xo + vt
d�nde x0 es la posici�n inicial, v la velocidad y t el tiempo transcurrido. Suponed que los tres datos son reales.*/

#include<iostream>
#include<cmath>
using namespace std;
int main (){
	double inicial, velocidad, tiempo, final; // inicial y final se refieren a la posici�n del objeto
	cout << "Introduce la velocidad (en m/s) del cuerpo: "; 
	cin >> velocidad;
	cout << "\nIntroduce el tiempo (en segundos) transcurrido: ";
	cin >> tiempo;
	cout << "\nIntroduce la posici�n (eje x) inicial  del cuerpo: ";
	cin >> inicial;
	final = inicial + velocidad*tiempo;
	cout << "\nLa posici�n final del cuerpo es: " << final << " (x)";
}



