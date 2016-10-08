//lee imagenes/gio.pgm y la convierte en ascii con los caracteres "@%#*+=-:. "
#include<iostream>
#include<imagen.h>

using namespace std;

int main(){
    char grises[] = "@#%xo;:,. ";

    char arteASCII[4501]; // 4500 + el \0  	DEPENDIENDO QUE TAMAÑO TENGA LA IMAGEN, DEBO DE AUMENTAR O NO importante
       
    Imagen origen;

    // Leer la imagen gio.pgm
    if (!origen.leerImagen("imagenes/gio.pgm")){//si cambio el nombre por gato.pgm o lena.pgm etc me creara lo que le meta
	   cerr << "error leyendo imagenes/gio.pgm\n";
	   return 1;
    }
	
    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, 4500))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;  
	
    cout << "Ahora Forzamos que no quepa. Debe aparecer un mensaje de error\n";
    if(origen.aArteASCII(grises, arteASCII, 4199))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;
}
