#include "alumno.h"


stAlumno cargaUnAlumno(){

    stAlumno alumno;

    char aux[100];

    printf("\n Ingrese el nro de legajo: ");
    scanf("%d",&alumno.legajo);

    printf("\n Ingrese el dni:  ");
    fflush(stdin);
    scanf("%s",aux);
    strcpy(alumno.dni,aux);


    printf("\n Ingrese el nombre:  ");
    fflush(stdin);
    scanf("%s",aux);
    strcpy(alumno.nombre,aux);


    printf("\n Ingrese el apellido:  ");
    fflush(stdin);
    scanf("%s",aux);
    strcpy(alumno.apellido,aux);

    printf("\n Ingrese el dia de nacimiento: ");
    scanf("%d",&alumno.dia);

    printf("\n Ingrese el mes de nacimiento: ");
    scanf("%d",&alumno.mes);

    printf("\n Ingrese el dia de nacimiento: ");
    scanf("%d",&alumno.anio);

    printf("\n Ingrese el genero ('m' ,  'f', 'x' ) ");
    fflush(stdin);
    scanf("%c",&alumno.genero);

    alumno.domicilio = cargaUnaDireccion();

    return alumno;
}


void mostrarUnAlumno(stAlumno alumno){

    printf("\n---------------------------------\n");
    printf("Legajo:.................. %d \n",alumno.legajo);
    printf("Nombre:............... %s \n",alumno.nombre);
    printf("Apellido:............. %s \n",alumno.apellido);
    printf("DNI:.................. %s \n",alumno.dni);
    printf("Fecha Nacimiento:..... %d - %d - %d \n",alumno.dia, alumno.mes, alumno.anio);
    printf("Genero:.................. %c \n",alumno.genero);
    printf("<<<< DOMICILIO-INFO >>>>:")
    mostrarUnaDireccion(alumno.domicilio);
    printf("\n---------------------------------\n");

}
