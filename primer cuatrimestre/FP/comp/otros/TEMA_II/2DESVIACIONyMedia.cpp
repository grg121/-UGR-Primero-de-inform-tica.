/* El programa calcula la media aritmética muestral y la desviación típica de las alturas de tres personas.
 Estos valores serán reales.*/

#include<cmath>
#include<iostream>
using namespace std;
int main (){
	double altura1, altura2, altura3, media,desviacion;
	double cuadrado1, cuadrado2, cuadrado3; //Para trabajar de forma más exacta
	bool altura1_mayor, altura2_mayor, altura3_mayor;
	string mayor, menor;
	mayor = " es mayor que la media.";
	menor = " es menor o igual que la media.";

	cout << "Introduce las alturas de las tres personas. Deben ser del tipo \"1.76\" \nLos datos deben introducirse separados por un espacio y una vez \nintroducidos, debes pulsar Enter.\n";
	cin >> altura1 >> altura2 >> altura3;
	media = (altura1 + altura2 + altura3)/3;
	cout << "La media de las alturas (en metros) es: " << media ;
	cuadrado1 = pow((altura1 - media),2) ;
	cuadrado2 = pow((altura2 - media),2) ;
	cuadrado3 = pow((altura3 - media),2);
	desviacion = sqrt((cuadrado1 + cuadrado2 + cuadrado3)/3);
	cout << "\nLa desviación típica es de: " << desviacion;
    altura1_mayor = (altura1 > media);
    altura2_mayor = (altura2 > media);
    altura3_mayor = (altura3 > media);



    cout << "\n" << altura1;
    if (altura1_mayor)
        cout << mayor;
    else
        cout << menor;

    cout << "\n" << altura2 ;

    if (altura2_mayor)
        cout << mayor;
    else
        cout << menor;

    cout << "\n" << altura3;

    if (altura3_mayor)
        cout << mayor;
    else
        cout << menor;






}//Por Francisco Navarro Morales - GRG121
