#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double millas;
	double kilometros;
	
	cout << " introduce el valor en millas " ;
	cin >> millas;
	
	kilometros = millas*1.609;
	
	cout << "\nEl valor en kilómetros es: " << kilometros << "n\n";
	system("pause");
}
