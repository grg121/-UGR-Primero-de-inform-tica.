#include<iostream>
#include<cmath>
using namespace std;
int main (){
   double a�os,dias,horas,minutos,segundos ;
	cout << "Un valor de segundos de: ";
	cin >> segundos;
	a�os = 31536000 * segundos ;
	dias = 86400 * segundos ;
	horas = 3600 * segundos ;
	minutos = 60 * segundos ;
	segundos = segundos % 60;
	minutos = segundos / 60;
   resto = segundos % 60;
   cout << "Es igual a " << a�os << " a�os, " << dias << " d�as,  " << horas << "horas, "<< minutos << " minutos y " << segundos << " segundos \n";
   system ("pause");
}
