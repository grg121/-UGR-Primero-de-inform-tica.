#include<iostream>
using namespace std; 



	class Acumulador{
		double suma ; 
		double cuadrados ; 
		int n ; 
	public: 
		Acumulador();
		void acumular(double dato) ; 
		double nDatos() const { return n ; }
		double media() const { return suma / n ; }
		double varianza()  const ;
	
	} ;  


	Acumulador::Acumulador(){
		suma = cuadrados = 0 ; 
		n = 0 ; 
	}
	
	void Acumulador::acumular(double dato){
		suma += dato ; 
		cuadrados += dato*dato ; 
		n++ ; 
	}

	double Acumulador::varianza() const { 
		double med = media() ; 
		return(cuadrados/n - (med*med)) ; 
	}




int main(){
	Acumulador ac ; 
	
	double dato = 0 ; 

	cout << "Introduce datos hasta terminar con un valor negativo: " ;
	
	cin >> dato ; 	

	while(dato >= 0){ 
		ac.acumular(dato) ; 
		cin >> dato ; 
		
	}

	if(ac.nDatos() == 0) cout << "Error. Sin datos. " << endl ; 
	else{ cout << " Datos leídos: " << ac.nDatos() 
	          << "\nMedia: "       << ac.media() 
		  << "\nVarianza: "    << ac.varianza() ; 
	}
}








