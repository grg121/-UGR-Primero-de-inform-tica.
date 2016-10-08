#include<iostream>
#include<cmath>
using namespace std;
int main (){
   int anhos , dias , horas , minutos , segundos;
	cout << "Un valor de segundos de: ";
	cin >> segundos;
	anhos = segundos / 31536000 ;
	dias = segundos % 31536000 * 365 segundos / 86400 ;
	horas = segundos / 3600 ;
	minutos = segundos / 60 ;
	segundos = segundos % 60;
   cout << "Es igual a " << anhos << " años, " << dias << " días,  " << horas << " horas, "<< minutos << " minutos y " << segundos << " segundos \n";
 cout << endl << "Adiós" << endl ;
}
