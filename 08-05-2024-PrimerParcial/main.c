#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>

int cantidadElementosPila(Pila p);
void cargarPila(Pila * p, char mensaje[]);
void pasarPila(Pila * origen, Pila * destino);
void mostrarPila(Pila p);
int sumaElementosPila(Pila p);
float calculaPromedioPila (Pila p);
int insertaElementoEnArregloOrdenado(int a[], int v, int dim, int dato);
void mostrarArreglo(int a[], int v);
int pilaToArregloOrdenadoMayores(Pila p, int a[], int v, int dim, float promedio);
int buscaPosElemento(int a[], int v, int dato);



int main()
{
    printf("Hello world!\n");

    Pila p;
    inicpila(&p);

    float promedio;

    cargarPila(&p, "Ingrese un valor entero. MIN 0 MAX 100\n");
    mostrarPila(p);

    promedio = calculaPromedioPila(p);

    printf("El promedio es %f",promedio);


    int arreglo[10] = {0}; // 3
    int v = 0;

    v = pilaToArregloOrdenadoMayores(p,arreglo,v,10,promedio);


    printf("\n");
    mostrarArreglo(arreglo,v);

    int posMenor = buscaPosElemento(arreglo,v, 95);

    printf("La posicion del elemento  %d  es  %d ", 95, posMenor);




    return 0;
}


/**
 1. Hacer una función que permita al usuario cargar en una pila 50 valores como máximo.
Tantos valores como quiera el usuario, sin sobrepasar la dimensión.
Esta función NO DEBE USAR la funcion leer() de la libreria Pilas.
No debe haber valores negativos y maximo 100.
Además debe recibir cómo parametro un STRING (cadena de caracteres)
en donde reciba el mensaje que se le va a mostrar al usuario dentro
de la función cuando va a ingresar un dato.
**/


int cantidadElementosPila(Pila p)
{
    Pila aux;
    inicpila(&aux);

    int i = 0;
    while(!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
        i++;
    }

    return i;
}


void cargarPila(Pila * p, char mensaje[])
{
    int cant = cantidadElementosPila(*p);

    char option = 0;
    int dato;

    while(cant < 50 && option != 27)
    {

        printf("\nMensaje: %s",mensaje);
        scanf("%d", &dato);

        if(dato <= 100 && dato >=0)
        {
            apilar(p,dato);
            cant ++;
        }
        else
        {
            printf("El dato no es válido. \n");

        }

        printf("Desea ingresar mas informacion? ESC para salir");
        fflush(stdin);
        option = getch();
        system("cls");

    }

}

/**
2. Hacer una funcion que muestre los elementos de una pila.
No debe utilizar la función mostrar() de la libreria de pilas.
Tener en cuenta cuál es la manera optima de recibir la pila que vamos a utilizar en la función.
**/

void pasarPila(Pila * origen, Pila * destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino,desapilar(origen));
    }

}

void mostrarPila(Pila p)
{
    Pila aux;
    inicpila(&aux);
    pasarPila(&p,&aux);

    printf("\n base - ");
    while(!pilavacia(&aux))
    {
        printf(" %d | ", tope(&aux));
        apilar(&p,desapilar(&aux));
    }
    printf(" - tope \n ");


}


/**
3. Hacer una función que cuente la cantidad de elementos de la pila.
4. Hacer una función que sume la cantidad de elementos de la pila.
5. Hacer una función de tipo float que calcule el promedio los valores de la pila y lo retorne.
La pila debe quedar con todos sus elementos una vez finalizadas todas la funciones.
**/


int sumaElementosPila(Pila p)
{

    int suma = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        suma = suma + tope(&p);
        apilar(&aux, desapilar(&p));
    }

    return suma;

}


float calculaPromedioPila (Pila p)
{
    return (float) sumaElementosPila(p) / (float) cantidadElementosPila(p);
}


/**
6. Hacer una función que agregue un elemento en un arreglo ordenado conservando el orden.
Esta funcion debe recibir el arreglo, sus validos, su dimension y el dato a insertar,
debiendo retornar la cantidad de elementos ingresados.
Deben tener en cuenta que el arreglo puede tener datos previamente.
**/


int insertaElementoEnArregloOrdenado(int a[], int v, int dim, int dato)
{
    int i = v - 1;

    if(v < dim)
    {

        while( i >= 0 &&  a[i] > dato )
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = dato;
    }

    return v + 1;

}


void mostrarArreglo(int a[], int v)
{
    for(int i = 0; i < v; i++)
    {
        printf(" %d | ", a[i]);
    }
}

/**
 7. Hacer una función que reciba como parámetro una pila (origen de datos),
  un arreglo (de 50 enteros de dimension) y el promedio.
  Esta función debe recorrer la pila y si el valor del tope es mayor al promedio,
  debe llamar a la función de insertarDatoenArregloOrdenado (del punto anterior) e
  insertar en el arreglo ese dato. La función debe devolver la cantidad de datos ingresados al arreglo.
**/

int pilaToArregloOrdenadoMayores(Pila p, int a[], int v, int dim, float promedio)
{

    Pila aux;
    inicpila(&aux);


    while(!pilavacia(&p) && v < dim)
    {
        if(tope(&p) > promedio)
        {
            v = insertaElementoEnArregloOrdenado(a,v,dim,desapilar(&p));
        }
        else
        {
            apilar(&aux,desapilar(&p));
        }
    }

    return v;
}

/**
8. Hacer una funcion que busque un elemento dentro del arreglo,
 en caso de que exista en el elemento, debe retornar la posición del mismo;
 caso contrario, debe retornar -1. Contemplar todos los escenarios posibles (arreglo vacio, con informacion)

**/


int buscaPosElemento(int a[], int v, int dato)
{

    int pos = -1;
    int i = 0;
    int flag  = 0;

    if(v > 0)
    {

        while(i < v && flag == 0)
        {
            if(a[i] == dato)
            {
                flag = 1;
                pos = i;
            }

            i++;

        }

    }

    return pos;

}








