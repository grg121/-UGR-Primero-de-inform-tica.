//NOMBRE:Francisco Navaro Morales 54202078-W
//PROBLEMA: conjunto
#include<iostream>
using namespace std;

class MiSecuenciaEnteros{
private:
      static const int CAPACIDAD = 50 ;
      int pvector[CAPACIDAD];
      int total_utilizados ;

public:
      MiSecuenciaEnteros()
         :total_utilizados(0){
         }

      int TotalUtilizados(){
         return total_utilizados;
      }

      int Capacidad(){
         return CAPACIDAD ;
      }

      void Add(int componente){
         if(total_utilizados < CAPACIDAD){
         pvector[total_utilizados] = componente ;
         total_utilizados++ ;
         }
      }

      int Elemento(int posicion){
         return pvector[posicion] ;
      }

      int Buscar(int elemento){
         int i = 0 ;
         while(pvector[i] != elemento && i < total_utilizados){
               i++;
         }
         if(i == total_utilizados)
            i = -1 ;

         return i ;
      }

      void MuestraEnPantalla(){
         for(int i = 0 ; i < total_utilizados ; i++)
            cout << pvector[i] << " " ;
      }

      MiSecuenciaEnteros Simplifica(){
         MiSecuenciaEnteros simplificada ;
         int i ;
         for( i = 0 ; i < total_utilizados ; i++){
            if(simplificada.Buscar(pvector[i]) == -1)
               simplificada.Add(pvector[i]);
         }
         return simplificada ;
      }

      };

int main(){

   MiSecuenciaEnteros secuencia_de_entrada ;

   cout << "Vamos a trabajar con una secuencia de enteros."
        << "\nLa capacidad de la secuencia es de " << secuencia_de_entrada.Capacidad() << " enteros."
        << "\nEl 0 no se considera un valor posible para la secuencia." << endl ;



   cout << "\nA continuacion, introduce los elementos de la secuencia de enteros."
        << "\n-Debes introducir los enteros separados por un espacio. "
        << "\n-Debes señalar el final de la secuencia introduciendo como ultimo valor el 0." << endl ;

   int lectura ;


   cout << "\Introduce los valores: " ;

   cin >> lectura ;

   while(lectura != 0){
         secuencia_de_entrada.Add(lectura) ;
         cin >> lectura ;

   }

   cout << "\nHa finalizado la introduccion de datos."
        << "\nLa secuencia introducida ha sido: \n\n " ;

   secuencia_de_entrada.MuestraEnPantalla() ;

   cout << endl ;

   MiSecuenciaEnteros simplificada(secuencia_de_entrada.Simplifica()) ;

   cout << "\nEl contenido de la secuencia simplificada es: \n\n " ;

   simplificada.MuestraEnPantalla() ;

   cout << endl ;






}



