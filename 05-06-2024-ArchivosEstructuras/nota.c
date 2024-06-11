#include "nota.h"

stNota crearUnaNota(){

    stNota n;

    printf("\n Ingrese la nota: \n");
    scanf("%d",&n.valor);

    printf("\n Ingrese el nombre de la materia\n");
    fflush(stdin);
    gets(n.nombreMateria);

    return n ;

}
void mostrarUnaNota(stNota n){

    printf("\n---------------------------------\n");
    printf("Id Nota:.................. %d \n",n.idNota);
    printf("Legajo del alumno:........ %d \n",n.legajoAlumno);
    printf("Materia:.................. %s \n",n.nombreMateria);
    printf("Valor nota:............... %d \n",n.valor);
    printf("\n--------------------------------------------\n");
}
