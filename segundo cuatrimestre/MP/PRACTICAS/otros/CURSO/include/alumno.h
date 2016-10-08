#include"examen.h"


#ifndef _ALUMNO_H_
#define _ALUMNO_H_

	struct alumno {
		static const int MAX = 10 ;
		examen examenes[MAX] ;
		int evaluaciones ;
		char nombre[50] ;
		char apellido[50] ;
	};

void NuevoAlumno(alumno entrada);
void NumeroExamenes(alumno entrada, int numero);
void AddExamenes(alumno entrada);
double NotaMedia(alumno entrada) ;
double NotaMax(alumno entrada) ;
double NotaMin(alumno entrada) ;
void ImprimeDatos(alumno entrada) ;


#endif
