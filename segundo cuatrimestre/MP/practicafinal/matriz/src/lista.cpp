#include <string>
#include <fstream>
#include "lista.h"

using namespace std;
//-------------------------------------------------------------------------------------------------------------------
Lista::Lista()
{
  cabecera = NULL ;

}
//-------------------------------------------------------------------------------------------------------------------
Lista::Lista(string valor)
{
  cabecera = new Celda ;//reserva de una celda

  cabecera->datos = valor ;//ponemos flecha pk cabecera es un puntero

  cabecera->siguiente =   NULL ; //el ultimo debe de apuntar a null 

}
//-------------------------------------------------------------------------------------------------------------------

 Lista::~Lista()
{

  Celda *borra ;//
		while(cabecera != NULL)
		{
    			borra = cabecera ;
    			cabecera = cabecera->siguiente ;
    			delete  borra ; //en una lista ojo si ponemos []
  		}

}
//-------------------------------------------------------------------------------------------------------------------
void Lista::destruir()
{

  Celda *borra ;//
		while(cabecera != NULL)//no puedo poner cabecera->siguiente!=NULL pk tendriamos el mismo fallo de antes, el ultimo no lo borra y si la cabecera esta bacia me petaria poniendo(while(cabecera->siguiente!=NULL))
		{
    			borra = cabecera ;
    			cabecera = cabecera->siguiente ;
    			delete  borra ; //en una lista ojo si ponemos []
  		}

}
//-------------------------------------------------------------------------------------------------------------------
Lista::Lista(const Lista & orig )
{
	cabecera = NULL;
	if(orig.cabecera !=0)
	{
		int tam=orig.longitud();
		string cadena;
		for(int i=0; i<tam; i++)
		{
				cadena=orig.getCelda(i);
				insertar(cadena);
		}
		
		//Otra manera de hacer lo mismo
		/*Celda *lectura=orig.cabecera;
		//Celda *escritura=this->cabecera;
		
		while(lectura!=NULL)
		{
			insertar(lectura->datos);
			lectura=lectura->siguiente;
		}	*/
	}
	else
		cabecera=NULL;
}	
//-------------------------------------------------------------------------------------------------------------------
Lista & Lista::operator=(const Lista &L2)
{
	if(this!= &L2)
	{
		if(L2.cabecera)
		{
			destruir();
			int tam=L2.longitud();
			string cadena;
			for(int i=0; i<tam; i++)
			{
				cadena=L2.getCelda(i);
				insertar(cadena);
			}
		}
		else
			this -> cabecera =NULL;
	}
	//ESTA SERIA OTRA OPCION PERO EN LA CABECERA SE PONDRIA Lista & Lista::operator=(const Lista *&L2);
	/*Celda *borra ;
		while(cabecera != NULL)
		{
    			borra = cabecera ;
    			cabecera = cabecera->siguiente ;
    			delete  borra ; //en una lista ojo si ponemos []
  		}
  	Celda *lectura=L2->cabecera; //creamos otro puntero celda y con el vamos avanzando	
  	while(lectura!=NULL)
	{
			insertar(lectura->datos);
			lectura=lectura->siguiente;
	}	*/
  	return *this;	
}	
//-------------------------------------------------------------------------------------------------------------------
// En el operador + para poder realizar: L=L+S, siendo L una LIsta y S un string 
Lista Lista::operator + (const string & otro)const
{
	Lista suma;
	suma.insertar(otro);//el metodo insertar debe de estar en el lado private
	return suma;
}
//-------------------------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------------------------
string Lista::getCelda(int pos) const
{
	
	int contador=0;
	string resultado = "";	//ME LO PUEDO AHORRAR
	Celda *aux;
	aux=cabecera;
	while(aux !=NULL && contador < pos)
	{
		contador++;
		aux=aux->siguiente;
	}
	if(aux!=NULL)//para saber que el puntero esta apuntando a una celda, o sea que tenga datos
	{
		resultado=aux->datos;//ES FLECHA PK AUX ES UNA CELDA DE LA LISTA DE TIPO PUNTERO A UNA CELDA
	}
	return resultado;//PUEDO PONER return aux->datos, en el if y me ahorro string resultado 

  
}
//-------------------------------------------------------------------------------------------------------------------
/*
	Lista celdas;
	int nºdatos=celdas.longitud();
*/
//-------------------------------------------------------------------------------------------------------------------
int Lista::longitud() const
{


  int salida = 0 ;//la tengo que crear a la fuerza pk no tengo un int en celdas o cabeceras que represente el tamanio

  if(cabecera)
  {
 	 Celda * puntero = cabecera ;/*me creo un puntero nuevo pk si le hago cabecera=cabecera->siguiente, ya no se donde apuntan los datos 
					iniciales, no tengo que generar reserva, solo que apunte*/
  	while ( puntero != NULL)//no pongo puntero->siguiente!=NULL pk el ultimo no lo contaria.
	{
		salida++ ;//si pongo salida despues de punter=puntero->siguiente, siempre obtendre uno menos
    	puntero = puntero->siguiente ;
    		
  	}
}

  return salida ;
}
//-------------------------------------------------------------------------------------------------------------------
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
		getline(fin,grises); //la primera linea se ignora ¿¿como?? creo que no se ignora, se almacena en grises.
		fin >> lineas; //leo el numero de datos de grises y lo almaceno en lineas
		getline(fin,grises); //leer salto de linea y lo almaceno en grises CREO QUE LA 1º LINEA DESAPARECE PK SE SOBRESCRIBE CON EL SALTO DE LINEA
		if (!fin){
			return false;//¿¿no lo entiendo este bucle?? creo que es si no se ha abierto el bucle
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){//¿PK FIN?
				if (grises != ""){
					insertar(grises);//meto la cadena de caracteres en una celda nueva (habra 4 celdas)
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres siguiente y la insertaremos en el if
			}
		}
		fin.close();
	}
	return true;
}
