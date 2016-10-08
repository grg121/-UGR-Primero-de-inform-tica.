#include "compra.h"

// incrementa el precio de cada producto en un k %
void incrementarPrecios(Compra &c, int k){
	for (int i=0 ; i < c.MAX ; i++)
		c.lista[i].precio_kg += c.lista[i].precio_kg * k/100 ;
}

// muestra el listado de productos comprados
void listarCompra(const Compra &c){

  for (int i= 0 ; i < c.MAX ; i++){
	    cout << c.lista[i].nombre
           << "\t"   << c.lista[i].peso
	   << "\t" << c.lista[i].precio_kg << endl;
	}

}


// función que devuelve el importe total de la compra (sinIVA) y su peso (en kgs)
void obtenerImporteYPeso(const Compra &c, float &precio, int &peso){
	for(int i=0 ; i<c.MAX ; i++){
	   peso += c.lista[i].peso ;
	   precio += c.lista[i].precio_kg ;
	}

  peso /= 1000 ;
}

// función que muestra el "ticket" de compra según el formato sugerido
void mostrarTicketCompra(const Compra &c){
	listarCompra(c) ;

 float precio = 0 ;
 int peso = 0  ;

 }

void obtenerImporteYPeso(Compra &c, float &precio, int &peso){

 double iva = precio*21/100 ;

  cout << "Subtotal: " << "\t\t" << precio << endl;

  cout << "IVA (21%): " << "\t\t" << iva << endl ;

  cout << "Total de la compra: " << "\t" << precio+iva << endl ;



}
