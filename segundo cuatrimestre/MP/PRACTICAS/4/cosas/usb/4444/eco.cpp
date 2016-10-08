#include<iostream>
#include<fstream>
using namespace std;
int main(){

	char caracter ;

	string cadena ="" ; 

	ifstream fentrada;
	

	fentrada.open("datos.txt") ;

	ofstream fsalida;

	fsalida.open("salida.txt") ; 


	fentrada >> caracter ;



	while(caracter != '#'){

	cadena += caracter ; 

	fentrada >> caracter ;
	
} ;

	fsalida << cadena ;

	fentrada.close() ;

	fsalida.close() ;
}
