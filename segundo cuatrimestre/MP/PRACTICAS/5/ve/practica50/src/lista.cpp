#include <string>
#include <fstream>
#include "lista.h"

using namespace std;

Lista::Lista(){
  cabecera = NULL ;

}

Lista::Lista(string valor){
  cabecera = new Celda ;

  cabecera->datos = valor ;

  cabecera->siguiente =   NULL ;

}



void Lista::destruir(){

  Celda *borra ;

  if(cabecera != NULL){

  while(cabecera->siguiente != NULL){
    borra = cabecera ;
    cabecera = cabecera->siguiente ;
    delete [] borra ;
  }

  if(cabecera)
    delete [] cabecera ;
}

}

void Lista::insertar(string valor){

  if(cabecera){

  Celda *puntero = cabecera ;

  while(puntero->siguiente != NULL){
    puntero = puntero->siguiente ; /* lo hacemos para encontrar la última celta
   introducida (ultima posicion de memoria). */
  }
//una vez encontrada, reservamos memoria nueva en el puntero "siguiente" de esta última celda
  puntero->siguiente = new Celda ;

  puntero->siguiente->datos = valor ;

  puntero->siguiente->siguiente = NULL ;
} else cabecera = new Celda ; /* Si la cabecera está vacía la parte de puntero->siguiente
genera un error. Entonces hay que contemplar este caso y reservar directamente en cabecera. */
cabecera->siguiente = NULL ;
cabecera->datos = valor ;
}

string Lista::getCelda(int pos) const{

  bool out = cabecera ; // te va a devolver verdadero si hay contenido.

  string salida = " " ;

  if(out){

  Celda *puntero = cabecera ;

  int i ;

  for(i = 0 ;  i < pos && puntero->siguiente != NULL ; i++){
    puntero = puntero->siguiente ;
  } /* Si pos es mayor que el número de celdas, el bucle va a encontrar al NUL y va
  a parar. */

  if( pos == i){
    salida = puntero->datos ;
  } /* aqui comprueba que haya salida del bucle porque ha encontrado el dato y
  no porque haya encontrado un null. Si ha encontrado un null, no modifica salida
  y devuelve la cadena en blanco */

}

  return salida ;
}

int Lista::longitud() const{


  int salida = 0 ;

  if(cabecera){

  Celda * puntero = cabecera ;



  while ( puntero->siguiente != NULL){
    puntero = puntero->siguiente ;
    salida++ ;
  }
}

  return salida ;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura
 *
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda
 * en la lista. La función debe asegurarse de que la estructura sigue un patron
 * determinado, y se ha de crear la lista con el numero de elementos que contenga.
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();
	}
	return true;
}
