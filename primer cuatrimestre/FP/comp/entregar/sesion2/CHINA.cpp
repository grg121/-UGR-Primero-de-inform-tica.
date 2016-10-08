/*El programa reconoce la población inicial en un momento dado en China y el tiempo que debe transcurrir hasta el momento final, en qure
se quiere calcular la población. Finalmente, y atendiendo a los datos de natalidad, emigración y defunción pertinentes, imprime en pantalla
el resultado con la población tras el tiempo dado (en años). */
#include <iostream>
#include <cmath>

using namespace std;
int main (){
    cout << "Este programa calcula la variación de la población en China según los datos actuales (tasa de natalidad/mortalidad/emigración) Para ello, precisa de un valor inicial de la población y un tiempo transcurrido (en años). "
	double poblacion;
	double emigran, nacen, mueren, tiempo, year; 
	cout << "\n";
	cout << "Introduce la poblacion inicial: " ;
	cin >> poblacion;
	cout << "Introduce el tiempo transcurrido en años: " ;
	cin >> year;
	tiempo = year * 31536000;
	emigran = tiempo/71.9;
	nacen = tiempo/1.87;
	mueren = tiempo/3.27;
	poblacion = poblacion + nacen - emigran - mueren; //Aquí se calcula la variación total de la población por año. 
	cout << endl << "Adiós" << endl ;
	cout << "La poblacion en china en este tiempo será de: " << poblacion;
	
}//Por Francisco Navarro - GRG121@correo.ugr.es 
