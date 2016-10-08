#include<iostream>
#include<cmath>
using namespace std;

int main (){
	double Voltaje;
	double Intensidad;
	double Resistencia;

	cout << " Valor de la Intensidad: ";
	cin >> Intensidad;
	cout << " Valor de la Resistencia: ";
	cin >> Resistencia;

	Voltaje = Intensidad*Resistencia;

	cout << "\nEl voltaje es de: " << Voltaje;

}


