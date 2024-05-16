#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"
#include <time.h>
#include "pilaAlumno.h"


int main()
{
    srand(time(NULL));
    stAlumno alumno, b , c;

    PilaAlumnos pilita;
    inicPilaAlumnos(&pilita);

    alumno = cargaRandomAlumno();
    b = cargaRandomAlumno();
    c = cargaRandomAlumno();


    apilarPilaAlumnos(&pilita,alumno);
    apilarPilaAlumnos(&pilita,b);
    apilarPilaAlumnos(&pilita,c);

//    apilarPilaAlumnos(&pilita,c);

    mostrarPilaAlumnos(&pilita);


    //printf("Quiero un numero random: %d", randomRango(20,50));
    //printf("El peso en memoria del alumno es %d \n\n" , sizeof(stAlumno));


    return 0;
}













