#include<iostream>
#include"alumno.h"
#include"curso.h"
#include"head.h"
#include"examen.h"
using namespace std;

int main(){

  curso un_curso ;


  lee_linea(un_curso.nombre,50) ;
  cin >> un_curso.util_alumnos ;

  for(int i = 0 ; i < un_curso.util_alumnos ; i++){
    //NombrarAlumno(un_curso.alumnos[i]) ;
    cout << "al" ;
    lee_linea(un_curso.alumnos[i].nombre,50) ;
    lee_linea(un_curso.alumnos[i].apellidos, 50) ;
      cout << "\nn-exm";
    cin >> un_curso.alumnos[i].util_examenes ;
    for(int i = 0 ; i < un_curso.alumnos[i].util_examenes ; i++){

      lee_linea(un_curso.alumnos[i].examenes[i].asignatura,50) ;
      cin >> un_curso.alumnos[i].examenes[i].nota ;
    }
  }

  for(int i = 0 ; i < un_curso.util_alumnos ; i++){
    MostrarDatos(un_curso.alumnos[i]) ;
  }


cout << endl ;
return 0 ;

}
