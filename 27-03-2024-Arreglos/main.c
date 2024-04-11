#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"
#include <ctype.h>
#include <string.h>

#define DIM2 10

int cargaRandomArregloVacio(int arreglo[], int dimension, int cantidadElementos);
int cargaArreglo(int arreglo[],int v, int dim, char mensaje[40]);
void cargaArregloReferencia(int arreglo[],int * v, int dim);
void mostrarArreglo(int a[], int v);
void arregloToPila(int arreglo[], int validos, Pila * p);
int cuentaDatosPila(Pila p);


int intercambio(int * a, int * b);
int buscaPosicionMenorSeleccion(int arreglo[], int v, int inicio);
void ordenacionSeleccion(int arreglo[], int v);
int insertarArregloOrdenado(int arreglo[], int v, int dato);
void ordenacionInsercion(int arreglo[], int v);

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

    validosNotas = cargaArreglo(arregloNotas,validosNotas,DIM,"Ingrese una temperatura");
    mostrarArreglo(arregloNotas,validosNotas);

//    int menor = buscaMenorPosicion(arregloNotas,validosNotas);
//    printf("La posicion menor del arreglo es %d", menor);


    ordenacionInsercion(arregloNotas,validosNotas);
    mostrarArreglo(arregloNotas,validosNotas);




    //char oracion[50];
    //char palabra [] = "hola mundo";

    //printf("Ingrese una oracion \n");
    // fflush(stdin);
    //scanf("%s",&oracion);

    //gets(oracion);
    //printf("%d",strlen(oracion));

    //printf("%d", strcmp(oracion,palabra));

    /*

    char dniString[] = "435922";
    int nro = atoi(dniString);
    printf("%d \n ",nro +1);

    system("pause");

    int dni = 43592210;
    itoa(dni,oracion,10);
    printf("%s \n",oracion);
    printf("%c",oracion[0]);

    */


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
int cargaArreglo(int arreglo[],int v, int dim, char mensaje[40])
{

    char option;
    int dato;

    while(v<dim && option != 27)
    {
        printf("%s",mensaje);
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

    for(int i = 0; i<v; i++)
    {
        if(i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d |", a[i]);
    }
}

/// 3. Suma elementos de un arreglo
int sumaElementos(int arreglo[], int v){

    int suma = 0;
    for(int i = 0; i < v; i++){
        suma += arreglo[i];
    }
    return suma;
}




/***
* 4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
* cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
***/

void arregloToPila(int arreglo[], int validos, Pila * p)
{
    int cantPilas = cuentaDatosPila(*p);

    int posArreglo = 0;

    while(posArreglo < validos && cantPilas < 50)
    {

        apilar(p,arreglo[posArreglo]);
        cantPilas++;
        posArreglo++;
    }
}


/// Funcion que pasa los elementos de una pila al arreglo.

int pilaToArreglo(Pila *p, int arreglo[], int v, int dim)
{

    while(!pilavacia(p) && v < dim)
    {
        arreglo[v] = desapilar(p);
        v++;
    }

    return v;
}

/// 9. Realizar una función que determine si un arreglo es capicúa.
int esCapicua(int arreglo[], int v)
{

    int flag = 1;
    int inicio = 0;
    int fin = v-1;


    while(inicio<fin && flag == 1)
    {
        if(arreglo[inicio] == arreglo[fin])
        {
            inicio++;
            fin--;
        }
        else
        {
            flag = 0;
        }
    }

    return flag;
}
 /// 10. Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
int invertirArreglo(int arreglo[], int v)
{
    int inicio = 0;
    int fin = v-1;

    while(inicio < fin)
    {
        intercambio(&arreglo[inicio], &arreglo[fin]);
        inicio ++;
        fin--;
    }

}


int intercambio(int * a, int * b)
{

    int aux = *a;
    *a = *b;
    *b = aux;
}


int buscaMenorPosicion(int arreglo[], int v)
{

    int posMenor = -1;
    int i = 0;

    if(i<v)
    {
        posMenor = i;
    }

    for(i+1 ; i<v; i++)
    {
        if(arreglo[i] < arreglo[posMenor])
        {
            posMenor = i;
        }

    }

    return posMenor;
}


int buscaPosicionMenorSeleccion(int arreglo[], int v, int inicio)
{
    int posMenor = inicio;

    for ( int i = inicio + 1 ; i < v; i++)
    {
        if (arreglo[i] < arreglo[posMenor])
        {
            posMenor = i;
        }
    }

    return posMenor;
}



void ordenacionSeleccion(int arreglo[], int v)
{
    int i = 0;
    int posMenor;

    while(i<v)
    {
        posMenor = buscaPosicionMenorSeleccion(arreglo,v,i);
        intercambio(&arreglo[i],&arreglo[posMenor]);

        i++;
    }
}


//int insertarArregloOrdenado(int arreglo[], int v, int dato){
//    int i = v-1;
//
//    while( i <= 0 && arreglo[i] > dato){
//        arreglo[i+1] = arreglo[i];
//        i--;
//    }
//    arreglo[i+1] = dato;
//
//    return v + 1;
//}
//
//
//void ordenacionInsercion(int arreglo[], int v){
//
//    int i = 0;
//
//    while( i < (v-1) ){
//        insertarArregloOrdenado(arreglo,i,arreglo[i+1]);
//        i++;
//    }
//
//
//}


int insertarArregloOrdenado(int arreglo[], int v, int dato)
{
    int i = v - 1;

    while (i >= 0 && arreglo[i] > dato)
    {
        arreglo[i + 1] = arreglo[i];
        i--;
    }
    arreglo[i + 1] = dato;

    return v + 1;
}

void ordenacionInsercion(int arreglo[], int v)
{
    for (int i = 0; i < v; i++)
    {
        insertarArregloOrdenado(arreglo, i, arreglo[i]);
    }
}







/// FUNCIONES EXTRA
/// Funcion que carga elementos en un rango determinado
/// Funciones para cargar un arreglo sin numeros repetidos.



/// Extra para pilas
int cuentaDatosPila(Pila p)
{

    Pila aux;
    inicpila(&aux);
    int contador = 0;

    while(!pilavacia(&p))
    {
        apilar(&aux,desapilar(&p));
        contador ++;
    }

    return contador;

}
