#include<cmath>
#include<iostream>
using namespace std;
int main (){
	double radio, area, longitud;
	const double PI = 3.1416;
	cout << "el valor (en centímetros) del radio es: ";
	cin >> radio ;
	area = PI * radio * radio;
	longitud = 2 * PI * radio;
	cout << "el valor del area es de: " ;
		cout << area;
		cout << "cm \n";
	cout << "el valor de la longitud es de: ";
	   cout << longitud;
	   cout << "cm \n";
	system ("pause");
}
