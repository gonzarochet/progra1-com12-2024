#ifndef PILAALUMNO_H_INCLUDED
#define PILAALUMNO_H_INCLUDED

#include "alumno.h

typedef struct{
    stAlumno * a;
    int v;
    int dim;
}PilaAlumnos;

void inicPilaAlumnos(PilaAlumnos * p);
void apilarPilaAlumnos(PilaAlumnos * p, stAlumno dato);
stAlumno topePilaAlumnos(PilaAlumnos * p);
stAlumno desapilarPilaAlumnos(PilaAlumnos * p);
int pilaAlumnosVacia(PilaAlumnos * p);
void leerPilaAlumnos(PilaAlumnos * p, char mensaje[]);
void mostrarPilaAlumnos(PilaAlumnos * p);




#endif // PILAALUMNO_H_INCLUDED
