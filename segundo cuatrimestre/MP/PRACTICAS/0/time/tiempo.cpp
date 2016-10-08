#include<iostream>
using namespace std;

// Manejo de tiempos.

struct tiempo{
  int horas, min, sec ;
} ;


/* esPosterior: dados dos instantes de tiempo, devuelve true
si el segundo instante es POSTERIOR al primero y false
en caso contrario. */

bool esPosterior(tiempo t1, tiempo t2){
    bool salida = true ;
    if (t1.horas > t2.horas)
      salida = false ;
    else if (t1.horas == t2.horas){
      if (t1.min > t2.min)
        salida = false ;
      else if (t1.min == t2.min){
        if (t1.sec > t2.sec)
          salida = false ;
      }
    }

    return salida;
}

/*convertirASegundos: transforma el instante de tiempo dado, t, a un valor
en segundos. */

int convertirASegundos(tiempo t){
  int salida = t.sec;
  salida += t.min * 60 ;
  salida += t.horas * 3600 ;

  return salida;
}

/* obtenerNuevoTiempo: dados un instante de tiempo, t, y un valor entero, s,
(que representa una cantidad de segundos), devuelve un nuevo instante de
tiempo, t2, que representa la suma de s segundos a t. */

tiempo obtenerNuevoTiempo(tiempo t, int s){
  tiempo salida = t ;

  salida.sec += s ;

  /* Se añaden los segundos s y, a continuación, se ajustan los valores de
  segundos, minutos y horas para que sean correctos. */

  int div_sec = salida.sec/60 ;

  salida.sec %= 60 ;

  salida.min += div_sec ;

  int div_min = salida.min/60 ;

  salida.min %= 60 ;

  salida.horas += div_min ;

  salida.horas %= 24 ;

  return salida ;

}


int main(){

  //creamos dos tiempos para probar las funciones

  tiempo primero = {1, 1, 3} ;

  tiempo segundo = {1, 2, 4} ;

  cout << "\nNuestro primer tiempo es: " << primero.horas << " horas, "
  << primero.min << " minutos, y " << primero.sec << " segundos. " ;

  cout << "\nNuestro segundo tiempo es: " << segundo.horas << " horas, "
  << segundo.min << " minutos, y " << segundo.sec << " segundos. " ;



  // Prueba de convertirASegundos:

  int s_primero = convertirASegundos(primero) ;

  int s_segundo = convertirASegundos(segundo) ;

  cout << "\nEl primer tiempo es equivalente a " << s_primero << " segundos. " ;

  cout << "\nEl segundo tiempo es equivalente a " << s_segundo << " segundos. " ;

  // Prueba esPosterior

  if(esPosterior(primero, segundo))
    cout << "\nEl segundo tiempo es posterior al primero. " ;
  else
    cout << "\nEl primer tiempo es posterior al segundo. " ;

// Prueba de obtener nuevo tiempo

tiempo tercero = obtenerNuevoTiempo(primero, 30000) ;

cout << "\nNuestro tercer tiempo es: " << tercero.horas << " horas, "
<< tercero.min << " minutos, y " << tercero.sec << " segundos. " ;




 }
