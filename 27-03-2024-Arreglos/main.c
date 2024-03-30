#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM2 10
void mostrarArreglo(int a[], int v);
int cargaRandomArregloVacio(int arreglo[], int dimension, int cantidadElementos);


const int DIM = 10;


int main()
{

    srand(time(NULL));

    int arregloNotas[DIM];
    int validosNotas = 0;

//    int i;
//
//    for(i = 0; i< DIM ; i++){
//        arregloNotas[i] = rand()%10;
//    }
//
//    validosNotas = i;

    validosNotas = cargaRandomArregloVacio(arregloNotas,DIM,15);
    mostrarArreglo(arregloNotas,15);


     /*
    int arreglo  [20] = {0};
    int arreglo2 [DIM];

    mostrarArreglo(arreglo,20);
    printf("\n\n\n");
    mostrarArreglo(arreglo2,20);

    */


    return 0;
}

int cargaRandomArregloVacio(int arreglo[], int dimension, int cantidadElementos)
{

    int validos = 0;
    int i = 0;

    //if(cantidadElementos <dimension){
        for(i = 0; i< cantidadElementos; i++ ){
            arreglo[i] = rand()%10;
        }

        validos = i;
    //}

    return validos;
}









void mostrarArreglo(int a[], int v)
{
    for(int i = 0; i<v; i++)
    {
        if(i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d |", a[i]);
    }
}
