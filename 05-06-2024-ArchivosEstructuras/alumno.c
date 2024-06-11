#include "alumno.h"

stAlumno crearUnAlumno()
{
    stAlumno a;
    char aux[100];

    printf("\n Ingrese el nombre:  \n");
    fflush(stdin);
    gets(a.nombreYapellido);

    printf("Ingrese la edad \n");
    scanf("%d",&a.edad);

    printf("Ingrese el anio \n");
    scanf("%d",&a.anio);

    return a;

}


void mostrarUnAlumno(stAlumno a)
{
    printf("\n---------------------------------\n");
    printf("Legajo:.................. %d \n",a.legajo);
    printf("Nombre y Apellido:....... %s \n",a.nombreYapellido);
    printf("Edad:.................. %d \n",a.edad);
    printf("Anio:.................. %d \n",a.anio);
    printf("\n--------------------------------------------\n");
}
