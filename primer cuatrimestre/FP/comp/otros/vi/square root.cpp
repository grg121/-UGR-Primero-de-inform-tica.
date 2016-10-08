#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double lado1;
	double lado2;
	double hipotenusa;
	
	cout << "Introduce la longitud del primer cateto: ";
	cin >> lado1 ;
	cout << "Introduce la longitud del segundo cateto: ";
	cin >> lado2 ;
	
	hipotenusa = sqrt(lado1*lado1 + lado2*lado2);
	
	cout << "\nLa hipotenusa vale: " << hipotenusa << "\n";
	system("pause");
	
}


