#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//a�o que cursa, recordar que no podemos utilizar la � para definir variables
} stAlumno;


stAlumno crearUnAlumno();
void mostrarUnAlumno(stAlumno a);

#endif // ALUMNO_H_INCLUDED
