#include"examen.h"
#include"alumno.h"
#include"head.h"

#ifndef _CURSO_H_
#define _CURSO_H_

struct curso{
    char nombre[50] ;
    alumno alumnos[100] ;
    int util_alumnos ;
} ;

void LeeAlumnos(curso entrada) ;


#endif
