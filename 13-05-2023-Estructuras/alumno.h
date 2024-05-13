#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "direccion.h"

 typedef struct{

    int legajo;
    char dni[9];
    char nombre[30];
    char apellido[30];
    int dia;
    int mes;
    int anio;
    char genero;
    stDireccion domicilio;

}stAlumno;

stAlumno cargaUnAlumno();
void mostrarUnAlumno(stAlumno alumno);


#endif // ALUMNO_H_INCLUDED
