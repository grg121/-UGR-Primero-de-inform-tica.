#include"head.h"
#include"examen.h"
#ifndef _ALUMNO_H_
#define _ALUMNO_H_



struct alumno{
  char nombre[50] ;
  char apellidos[100] ;
  examen examenes[10] ;
  int util_examenes ;
};

void MostrarDatos(alumno entrada) ;
double NotaMedia(alumno entrada) ;
void NombrarAlumno(alumno entrada) ;
void LeerExamenes(alumno entrada) ;


#endif
