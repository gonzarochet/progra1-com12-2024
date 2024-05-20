#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"
#include <time.h>
#include "pilaAlumno.h"
#include <windows.h>

void cargarAlumnosAlArchivo(char nombreArchivo[]);
void mostrarDesdeElArchivo(char nombreArchivo[]);

#define AR_ALUMNOS "alumnos.dat"


int main()
{
    srand(time(NULL));

    cargarAlumnosAlArchivo(AR_ALUMNOS);
    printf("\n\n<<<<<<<<<<<<<<< LISTADO DESDE EL ARCHIVO >>>>>>>>>>>><<<<<<<>>>><\n\n");
    mostrarDesdeElArchivo(AR_ALUMNOS);


//    stAlumno alumno, b , c;
//
//    PilaAlumnos pilita;
//    inicPilaAlumnos(&pilita);
//
//    alumno = cargaRandomAlumno();
//    b = cargaRandomAlumno();
//    c = cargaRandomAlumno();
//
//
//    apilarPilaAlumnos(&pilita,alumno);
//    apilarPilaAlumnos(&pilita,b);
//    apilarPilaAlumnos(&pilita,c);
//
////    apilarPilaAlumnos(&pilita,c);
//
//    mostrarPilaAlumnos(&pilita);


    //printf("Quiero un numero random: %d", randomRango(20,50));
    //printf("El peso en memoria del alumno es %d \n\n" , sizeof(stAlumno));


    return 0;
}

void cargarAlumnosAlArchivo(char nombreArchivo[]){

    char opcion = 0;
    stAlumno a;
    int cant = 0;

    FILE * archi = fopen(nombreArchivo,"wb");

    if(archi != NULL) { /// if(archi)

        do{
            a = cargaRandomAlumno();
            cant = fwrite(&a,sizeof(stAlumno),1,archi);
            printf("\nFue escrito %d con exito\n",cant);

            printf("Quiere seguir cargando datos al archivo? Esc para salir\n");
            fflush(stdin);
            opcion = getch();

        }while(opcion != 27);

        fclose(archi);
    } else{
        printf("No se pudo abrir");
    }

}


void mostrarDesdeElArchivo(char nombreArchivo[]){

    stAlumno a;

    FILE * archi = fopen(nombreArchivo,"rb");

    if(archi) {

        while(fread(&a,sizeof(stAlumno),1,archi) > 0){
            mostrarUnAlumno(a);
        }

        fclose(archi);
    }else{

       printf("No se pudo abrir");
    }

}

/// Del archivo al arreglo
/// del arreglo al archivo
/// busqueda de un alumno en un archivo
/// cantidad de elementos en un archivo sin recorrerlo.















