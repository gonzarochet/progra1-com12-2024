#ifndef NOTA_H_INCLUDED
#define NOTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct{
    int idNota;
    int valor;
    int legajoAlumno;
    char nombreMateria[50];
}stNota;

stNota crearUnaNota();
void mostrarUnaNota(stNota n);
#endif // NOTA_H_INCLUDED
