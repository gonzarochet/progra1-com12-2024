#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"


int main()
{
    stAlumno a;

    printf("El peso en memoria del alumno es %d \n\n" , sizeof(stAlumno));
    a = cargaUnAlumno();
    mostrarUnAlumno(a);

    return 0;
}









