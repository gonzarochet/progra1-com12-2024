#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

#define DIM2 10

int cargaRandomArregloVacio(int arreglo[], int dimension, int cantidadElementos);
int cargaArreglo(int arreglo[],int v, int dim);
void cargaArregloReferencia(int arreglo[],int * v, int dim);
void mostrarArreglo(int a[], int v);
void arregloToPila(int arreglo[], int validos, Pila * p);
int cuentaDatosPila(Pila p);

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

    cargaArregloReferencia(arregloNotas,&validosNotas,DIM);
    mostrarArreglo(arregloNotas,validosNotas);


    /*
    int arreglo  [20] = {0};
    int arreglo2 [DIM];

    mostrarArreglo(arreglo,20);
    printf("\n\n\n");
    mostrarArreglo(arreglo2,20);

    */


    return 0;
}


/// 1.
int cargaArreglo(int arreglo[],int v, int dim)
{

    char option;
    int dato;

    while(v<dim && option != 27)
    {
        printf("Ingrese un dato\n");
        scanf("%d", &arreglo[v]);
        v++;

        printf("Quiere seguir cargando datos? Presione ESC para salir\n");
        option = getch();
        system("cls");
    }

    return v;

}


void cargaArregloReferencia(int arreglo[],int * v, int dim)
{

    char option;
    int dato;
    int i = *v;

    while(i<dim && option != 27)
    {
        printf("Ingrese un dato\n");
        scanf("%d", &arreglo[i]);
        i++;

        printf("Quiere seguir cargando datos? Presione ESC para salir\n");
        option = getch();
        system("cls");
    }

  *v = i;

}
 /// Esta funcion cada vez que se llama comienza a cargar elementos al arreglo desde la posicion 0 (cero)
int cargaRandomArregloVacio(int arreglo[], int dimension, int cantidadElementos)
{

    int validos = 0;
    int i = 0;

    for(i = 0; i< cantidadElementos; i++ )
    {
        arreglo[i] = rand()%10+1;
    }

    validos = i;
    //}

    return validos;
}

/// 2.
void mostrarArreglo(int a[], int v)
{
    printf("[");
    for(int i = 0; i<v; i++)
    {
        if(i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d |", a[i]);
    }
    printf("]");
}



/***
* 4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
* cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
***/

void arregloToPila(int arreglo[], int validos, Pila * p)
{
    int cantPilas = cuentaDatosPila(*p);

    int posArreglo = 0;

    while(posArreglo < validos && cantPilas < 50){

        apilar(p,arreglo[posArreglo]);
        cantPilas++;
        posArreglo++;
    }
}


int pilaToArreglo(Pila *p, int arreglo[], int v, int dim) {}


/// FUNCIONES EXTRA
/// Funcion que carga elementos en un rango determinado
/// Funciones para cargar un arreglo sin numeros repetidos.


int cuentaDatosPila(Pila p){

    Pila aux;
    inicpila(&aux);
    int contador = 0;

    while(!pilavacia(&p)){
        apilar(&aux,desapilar(&p));
        contador ++;
    }

    return contador;

}
