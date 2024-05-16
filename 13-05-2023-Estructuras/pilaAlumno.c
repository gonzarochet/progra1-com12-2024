#include "pilaAlumno.h"


void inicPilaAlumnos(PilaAlumnos * p){

    p->dim = 75;
    p->a = (stAlumno*) malloc(p->dim * sizeof(stAlumno));
    p->v = 0;
}




