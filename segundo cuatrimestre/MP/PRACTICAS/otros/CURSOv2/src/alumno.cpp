#include"alumno.h"
#include"head.h"
#include<iostream>
using namespace std;

double NotaMedia(alumno entrada){
  double media = 0 ;
  for(int i = 0 ; i < entrada.util_examenes; i++){
    media += entrada.examenes[i].nota ;
  } media /= entrada.util_examenes ;
  return media ;
}

void NombrarAlumno(alumno entrada){
  lee_linea(entrada.nombre,50) ;
  lee_linea(entrada.apellidos, 50) ;
}

void LeerExamenes(alumno entrada){
  cin >> entrada.util_examenes ;
  for(int i = 0 ; i < entrada.util_examenes ; i++){
    lee_linea(entrada.examenes[i].asignatura,50) ;
    cin >> entrada.examenes[i].nota ;
  }
}

void MostrarDatos(alumno entrada){
  cout << "\nNombre: " << entrada.nombre       ;
  cout << "\nApellidos: " << entrada.apellidos ;

  for(int i = 0 ; i < entrada.util_examenes ; i++){
    cout << "\n" << entrada.examenes[i].asignatura << ": " << entrada.examenes[i].nota ;
  }
}
