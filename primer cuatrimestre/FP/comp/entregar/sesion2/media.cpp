/* El programa calcula la media aritm�tica muestral y la desviaci�n t�pica de las alturas de tres personas.
 Estos valores ser�n reales.*/

#include<cmath>
#include<iostream>
using namespace std;
int main (){
	double altura1, altura2, altura3, media,desviacion;
	double dato_1, dato_2, dato_3; //Para trabajar de forma m�s exacta 
	cout << "Introduce las alturas de las tres personas. Deben ser del tipo \"1.76\" \nLos datos deben introducirse separados por un espacio y una vez \nintroducidos, debes pulsar Enter.\n";
	cin >> altura1 >> altura2 >> altura3;
	media = (altura1 + altura2 + altura3)/3;
	cout << "La media de las alturas (en metros) es: " << media ;
	dato_1 = (altura1 - media)**2 ; //una forma de elevar al cuadrado una expresi�n con decimales 
	dato_2 = (altura2 - media) * (altura2 - media) ; // estas operaciones producen aproximaciones. Pueden dar lugar a errores.
	dato_3 = (altura3 - media) * (altura3 - media) ;
	desviacion = sqrt((dato_1 + dato_2 + dato_3)/3);
	cout << "\nLa desviaci�n t�pica es de: " << desviacion; 
}//Por Francisco Navarro Morales - GRG121
