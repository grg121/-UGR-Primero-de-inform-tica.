/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;


const int MAXLONG = 1000000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(){
/*


	Lista nueva("federico") ;

	int longitud ;

	nueva.insertar("pepe") ;
	nueva.insertar("juan") ;
	nueva.insertar("luis") ;
	nueva.insertar("camaron") ;
	cout << nueva.getCelda(0) << endl ;
	cout << nueva.getCelda(1) << endl ;
	cout << nueva.getCelda(2) << endl ;
	cout << nueva.getCelda(3) << endl ;
	cout << nueva.getCelda(4) << endl ;

	longitud = nueva.longitud() ;

	cout << "la longitud es: " << longitud << endl ;

}

*/



    char ficheroGrises[MAXLONG];
    char ficheroImagen[MAXLONG];
    Imagen origen;
    Lista celdas;

	cout << "Introduzca nombre de la imagen: ";
	leelinea(ficheroImagen);


    // Leer la imagen desde fichero
    if (!origen.leerImagen(ficheroImagen)){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;
		return 1;
	} else cout << "Se ha leido la imagen correctamente. " << endl ;

	cout << "Introduzca el nombre de fichero con el conjunto de caracteres: ";
	leelinea(ficheroGrises);
	// Leer cadenas desde fichero
	if (celdas.leerLista(ficheroGrises)){
		cout << "La lista se ha leido correctamente ; " << endl ;
		// realizar las conversiones

		int longitud = celdas.longitud() ;

		cout << "longitud: " << longitud ;

		for(int i=0 ; i<longitud ; i++){
			cout << celdas.getCelda(i) << endl ;
		}

		cout << "\nend bucle. \n\n" ;

		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}else{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}
		// celdas.destruir(); // liberar memoria listas
		cout << "\nSe libera la memoria de lista. \n\n" ;
	}else{
		cerr << "Error lista de grises " << ficheroGrises << endl;
	}

    origen.destruir();   // liberar memoria imagen
		cout << "\nSe libera la memoria de la imagen. \n" ;
}
