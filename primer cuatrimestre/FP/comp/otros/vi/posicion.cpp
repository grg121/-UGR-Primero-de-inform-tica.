 /*Construid un programa para calcular la posición de un objeto que sigue un movimiento rectilíneo uniforme.
  La posición se calcula aplicando la siguiente fórmula:
xo + vt
dónde x0 es la posición inicial, v la velocidad y t el tiempo transcurrido. Suponed que los tres datos son reales.*/

#include<iostream>
#include<cmath>
using namespace std;
int main (){
	double inicial, velocidad, tiempo, final; // inicial y final se refieren a la posición del objeto
	cout << "Introduce la velocidad (en m/s) del cuerpo: "; 
	cin >> velocidad;
	cout << "\nIntroduce el tiempo (en segundos) transcurrido: ";
	cin >> tiempo;
	cout << "\nIntroduce la posición (eje x) inicial  del cuerpo: ";
	cin >> inicial;
	final = inicial + velocidad*tiempo;
	cout << "\nLa posición final del cuerpo es: " << final << " (x)";
}



