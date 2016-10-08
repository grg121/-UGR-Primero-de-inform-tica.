#include <string>
#include <fstream>
#include "lista.h"

using namespace std;

Lista::Lista()
{
  cabecera = NULL ;

}

Lista::Lista(string valor)
{
  cabecera = new Celda ;//reserva de una celda

  cabecera->datos = valor ;//ponemos flecha pk cabecera es un puntero

  cabecera->siguiente =   NULL ; //el ultimo debe de apuntar a null

}



void Lista::destruir()
{

  Celda *borra ;
		while(cabecera != NULL)
    //no puedo poner cabecera->siguiente!=NULL pk tendriamos el mismo fallo de antes, el ultimo no lo borra y si la cabecera esta bacia me petaria poniendo(while(cabecera->siguiente!=NULL))
		{
    			borra = cabecera ;
    			cabecera = cabecera->siguiente ;
    			delete [] borra ;
  	}


}

void Lista::insertar(string valor)
{

	Celda* nueva =new Celda;
	nueva->datos=valor;
	nueva->siguiente=NULL;
	if(cabecera==NULL)
	{
		cabecera=nueva;
	}
	else
	{
		Celda *aux = cabecera;
		while(aux->siguiente !=NULL)//AHORA SI ME INTERESA PONER ->siguiente PK QUIERO PARARME EN EL ULTIMO DATO.
		{
			aux=aux->siguiente;
		}
		aux->siguiente=nueva;//AQUI LA ULTIMA QUE APUNTA A NULL QUE CONTENGA NUEVA
	}

}

string Lista::getCelda(int pos) const
{

	int contador=0;
	string resultado = "";
	Celda *aux;
	aux=cabecera;
	while(aux !=NULL && contador < pos)
	{
		contador++;
		aux=aux->siguiente;
	}
	if(aux!=NULL)//para saber que el puntero esta apuntando a una celda, o sea que tenga datos
	{
		resultado=aux->datos;
	}
	return resultado;


}

int Lista::longitud() const
{


  int salida = 0 ;

  if(cabecera)
  {
 	 Celda * puntero = cabecera ;/*me creo un puntero nuevo pk si le hago cabecera=cabecera->siguiente, ya no se donde apuntan los datos
					iniciales, no tengo que generar reserva, solo que apunte*/
  	while ( puntero != NULL)//no pongo puntero->siguiente!=NULL pk el ultimo no lo contaria.
	{
		salida++ ;
    		puntero = puntero->siguiente ;

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
