/*El programa reconoce la poblaci�n inicial en un momento dado en China y el tiempo que debe transcurrir hasta el momento final, en qure
se quiere calcular la poblaci�n. Finalmente, y atendiendo a los datos de natalidad, emigraci�n y defunci�n pertinentes, imprime en pantalla
el resultado con la poblaci�n tras el tiempo dado (en a�os). */
#include <iostream>
#include <cmath>

using namespace std;
int main (){
    cout << "Este programa calcula la variaci�n de la poblaci�n en China seg�n los datos actuales (tasa de natalidad/mortalidad/emigraci�n) Para ello, precisa de un valor inicial de la poblaci�n y un tiempo transcurrido (en a�os). "
	double poblacion;
	double emigran, nacen, mueren, tiempo, year; 
	cout << "\n";
	cout << "Introduce la poblacion inicial: " ;
	cin >> poblacion;
	cout << "Introduce el tiempo transcurrido en a�os: " ;
	cin >> year;
	tiempo = year * 31536000;
	emigran = tiempo/71.9;
	nacen = tiempo/1.87;
	mueren = tiempo/3.27;
	poblacion = poblacion + nacen - emigran - mueren; //Aqu� se calcula la variaci�n total de la poblaci�n por a�o. 
	cout << endl << "Adi�s" << endl ;
	cout << "La poblacion en china en este tiempo ser� de: " << poblacion;
	
}//Por Francisco Navarro - GRG121@correo.ugr.es 
