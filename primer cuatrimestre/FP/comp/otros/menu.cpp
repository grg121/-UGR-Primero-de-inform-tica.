#include<iostream>
using namespace std;

	int MaximoDe(int a, int b){
		int maximo = a;
		if ( b > maximo )
			maximo = b ;
			return maximo ;
	}

	void Menu(){
		cout << "Menu: " << endl
	 << endl << " I. Introducir numeros. " 
	 << endl << " S. Suma "
	 << endl << " P. Producto" 
	 << endl << " M. Maximo"
	 << endl << " R. saliR"
	 << endl;
	}
		
	char Seleccion(char opcion){
		do{
		cin >> opcion ;
		if ( opcion >= 'a' && opcion <= 'z')
			opcion = opcion - ('a' - 'A');
			
		}while (opcion != 'I' && opcion != 'S' && opcion != 'P' && opcion != 'M' && opcion != 'R');
	return opcion ;
}
	


	int main(){
		string saltos ;
		saltos = "\n\n\n\n" ;
		int primero, segundo ; 
		bool salida; 
		int resultado; 
		char opcion ;
		cout << "Introduce dos numeros enteros: " ; 
		cin >> primero >> segundo ; 
		
		do{
		
		Menu(); 
		
		opcion = Seleccion(opcion) ;
		
		if (opcion == 'I'){
		
			cout << "Introduce dos numeros enteros: " ; 
			cin >> primero >> segundo ; }
			 
		else if (opcion == 'S')
			resultado = primero + segundo;
		
		else if (opcion == 'P')
			resultado = primero * segundo ;
		else if (opcion == 'M')
			resultado = MaximoDe(primero, segundo);
		salida = opcion == 'R' ;
		
		cout << saltos << "el resultado es: " << resultado  << "\n\n\n\n\n" ;
			}while(!salida);
				
		
	}
	
