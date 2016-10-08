//NOMBRE: Francisco Navarro Morales 54202078-W
//PROBLEMA: gimnasia

#include<iostream>
using namespace std;

void IntroX(){
   for (int i=0 ; i<4 ; i++){
   cout  << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" ;
   }
   cout  << "\n\n";
}

/* breve introducci�n del programa */

void Introduccion(){

   IntroX();

   cout << "Este programa determina cu�l es la puntuaci�n m�xima que se ha obtenido en un  \n"
        << "campeonato regional de gimnasia. Cada gimnasta tiene un dorsal y ser� puntuado \n"
        << "por tres jueces. La puntuaci�n de cada gimnasta es la media de la puntuaci�n   \n"
        << "\n\nPara continuar introduce el primer dorsal:                               \n\n";

   IntroX();
}

/*Funci�n que calcula la media de tres valores (para las puntuaciones) */

double MediaDe(double valor1, double valor2, double valor3){
   double media = (valor1 + valor2 + valor3)/3 ;
   return media ;
}

/*Permite introduccir el dorsal del participante, filtrando solo dorsales positivos y el 0) */

int IntroducirDorsal(){
   int dorsal ;

   do{
      cin >> dorsal;
   }while(dorsal < 0) ;

   return dorsal ;
}

/* Comprueba si la puntuacion es correcta; esto es, si est� entre 0.0 y 10.0 */

bool EsCorrecta(double puntuacion){
   bool correcto = puntuacion >= 0.0 && puntuacion <= 10.0;
   return correcto;
}

double IntroducirPuntuacion(){
   double puntuacion ;
   cin >> puntuacion ;
   return puntuacion ;
}


int main (){
   string salto = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;

   int dorsal;

   double puntuacion1, puntuacion2, puntuacion3,
          media,
          maximo = 0 ;

   bool puntuacion_correcta;


   Introduccion();

   dorsal = IntroducirDorsal();

   cout << salto ;

   cout << "Comienzo del programa. \n\n";



   while (dorsal != 0){

         cout << "\nIntroduce las 3 puntuaciones del participante (separadas por un espacio) \n\n";

         /*A continuaci�n, un filtro de puntuaciones correctas. Filtra puntuaciones de 3 en 3. Si, tras
         introducir 3 puntuaciones, una de ellas es inv�lida, no tiene en cuenta ninguna de las tres. */

         do{
         puntuacion1 = IntroducirPuntuacion() ;
         puntuacion2 = IntroducirPuntuacion() ;
         puntuacion3 = IntroducirPuntuacion() ;
         puntuacion_correcta = EsCorrecta(puntuacion1) && EsCorrecta(puntuacion2) && EsCorrecta(puntuacion3) ;
         }while(!puntuacion_correcta);


         media = MediaDe(puntuacion1, puntuacion2, puntuacion3);

         cout << "\nPuntuacion obtenida: " << media << endl ;

         if (media > maximo)
            maximo = media ;

         cout << "\nIntroduce el dorsal del participante: \n\n" ;

         dorsal = IntroducirDorsal() ;
   }

   cout  << salto
         << "\nLa puntuaci�n maxima obtenida ha sido: " << maximo << endl;

}

