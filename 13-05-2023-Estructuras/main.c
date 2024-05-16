#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"
#include <time.h>


int main()
{
    srand(time(NULL));
    stAlumno a;



    //printf("Quiero un numero random: %d", randomRango(20,50));
    //printf("El peso en memoria del alumno es %d \n\n" , sizeof(stAlumno));

    a = cargaRandomAlumno();
    mostrarUnAlumno(a);

    return 0;
}













