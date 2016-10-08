#include<cmath>
#include<iostream>
using namespace std;
int main (){
	double fuerza , masa , aceleracion;
	cout << "Valor de la masa: " ;
	cin >> masa;
	cout << "valor de la aceleración " ;
	cin >> aceleracion;
	fuerza = masa*aceleracion;
	cout << "El valor de la fuerza es: " << fuerza << "n\n" ;
	system("pause");
}
