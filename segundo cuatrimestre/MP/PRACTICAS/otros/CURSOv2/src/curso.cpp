#include<iostream>
using namespace std;
#include"alumno.h"
#include"head.h"
#include"curso.h"

void LeeAlumnos(curso entrada){
  for(int i = 0 ; i < entrada.util_alumnos ; i++){
    NombrarAlumno(entrada.alumnos[i]) ;
  //  LeerExamenes(entrada.alumnos[i]) ;
  }
}
