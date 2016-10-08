#include<iostream>
#include <byte.h>
using namespace std;

void on(byte &b, int pos)
{
	unsigned char mask=1;// ponemos 00000001
	mask=mask<<pos;	//movemos el uno  donde queremos encender el bit
	b=b|mask;//aplicamos el operador or(suma), haciendo que ese bit sea uno y el resto se queda como estaba
}

void off(byte &b, int pos)
{
	unsigned char mask=1;
	mask=mask<<pos;//pones el uno en la posicion que queramos
	mask=~mask;//luego lo negamos
	b&=mask;//le hago la operacion and --> es lo mismo  b=b&mask;
}
//Saber como es el estado del bit que miramos Y devolver true o falso dependiendo su estado
bool getbit(byte b, int pos)
{
	unsigned char mask=1;
	mask=mask<<pos;//pongo un uno en la posicion requerida
	b&=mask;//le hago un and y asi se como esta ese bit. 
	return (b!=0);//si hay alguno que es uno, es pk el bit que hemos consultado esta encendido
	
}
void encender(byte &b)
{
	unsigned char mask=0xFF;//meto todos unos en la mascara
	b|=mask;//convertimos todos a 1 osea encendidos
}

void apagar(byte &b)
{
	unsigned char mask=0;//meto todos cero
	b&=mask;
}
//La utilizaremos cuando queremos cambiar todo el vector byte entero. Usamos un vector booleano
void asignar(byte &b, const bool v[])
{
	unsigned char mask=0;
	b=mask; //b=0; es lo mismo y nos ahorramos las mascara
	for(int i = 0 ; i<8 ; i++)
	{
		if(v[i])//si la posicion v[i] contiene un uno, encendemos, si no, pues nada
		{
			on(b,7-i);//ojo que cuando introducimos en el bloqueLes el 1 equivale al 7
		}
	}
}

void volcar(byte b, bool v[])
{
	for(int i=0 ; i<8 ; i++)
	{
		v[i]=getbit(b,i);//La funcion getbit, devuelve true o false dependiento el estado del bit comparado.
			      //Entonces volcamos los estados de (b) en un booleano	 
					//if(getbit(b,7-i)) -->si el dato que mete getbit en el b de la posicion x es verdadero, metemos true o falso
	}					//{
}						//	v[i]=true;
						//}
						//else
						//	v[i]=FALSE;
//Cuantos hay encendidos y en que posicion			
void encendidos(byte b, int posic[], int &cuantos)
{
	bool vector[8];
	cuantos=0;
	volcar(b,vector);//le pasamos a vector los estados de los bit ((NO HACE FALTA PASAR POR REFERENCIA DEBIDO A QUE ES UN VECTOR))
  	
	


	for(int i=0 ; i<8 ; i++)
	{
		if(vector[i])//si los datos volcados en vector[] son TRUE(o sea 1), 
		{
			posic[cuantos]=i;//mentemos en posic los que estan activados a traves de i
			cuantos++;	//incrementamos cuantos para cuando haya un numero TRUE avancemos en el vector posic			
		}
	}
}

string byteToString(byte b)
{
	string salida="";//inicializamos
	
	for(int i=0; i<8 ; i++)	
	{	if(getbit(b,i))//si es verdadero es que esta encendido
		{
			salida+="1";//salida=salida + "1"
		}
		else						//La Forma de interpretarlo es que string es un vector de caracteres tipo c++
			salida+="0";//salida=salida + "0"	//cuando se le mete un 1 o 0 entre comillas es como si escribieras 									//holatio----01001001, 
	}return salida ;
}	
void print(byte b){		//ESTA FUNCION ES LA SUSTITUCION DE byteToString()
					//vasta con poner en el main print(b)
	for(int i = 7; i >= 0 ;i--){
		if(getbit(b,i)){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	cout << endl;
}	
		

