#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"


void cargarPilaRandom10Valores(Pila *p);
void intercambio ( int * a, int * b);
void muestraMayorMenor(int nro1, int nro2, int nro3);
int devuelveMayorPila(Pila * p);
int devuelveMayorPilaPorValor(Pila p);


int main()
{
    srand(time(NULL));

    Pila dada;
    inicpila(&dada);
    cargarPilaRandom(&dada);
    mostrar(&dada);

    int nro1 = 50;
    int nro2 = 20;

//    printf("Antes del intercambio\n");
//    printf( "El valor de nro 1 es %d \n", nro1);
//    printf("El valor de nro 2 es %d \n", nro2);
//
//
//
//    intercambio(&nro1,&nro2);
//
//    printf("Despues del intercambio\n");
//    printf( "El valor de nro 1 es %d \n", nro1);
//    printf("El valor de nro 2 es %d \n", nro2);
//
//
//    muestraMayorMenor(10,15,6);


    int valorMayor = devuelveMayorPilaPorValor(dada);
    mostrar(&dada);

    printf("El valor mayor de la pila es %d \n", valorMayor);


    return 0;
}


void cargarPilaRandom(Pila *p)
{

    int nro = 0;


    for(int i = 0; i < 10 ; i++)
    {
        nro = rand()%10 +1;
        apilar(p,nro);
    }


}


void intercambio ( int * a, int * b)
{
    int aux;

    aux = *a ;
    *a = *b;
    *b = aux;

}

///. 2.	Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor.

void muestraMayorMenor(int nro1, int nro2, int nro3)
{

    int mayor;

    int menor;

    if(nro1 > nro2 && nro1 > nro3)
    {
        mayor = nro1;

        if(nro2 < nro3)
        {
            menor = nro2;

        }
        else
        {
            menor = nro3;
        }

    }
    else if ( nro2 > nro1 && nro2 > nro3)
    {

        mayor = nro2;

        if(nro1 < nro3)
        {
            menor = nro1;
        }
        else
        {
            menor  = nro3;
        }


    }
    else
    {
        mayor = nro3;


        if(nro1 < nro2)
        {
            menor = nro1;
        }
        else
        {
            menor  = nro2;
        }


    }


    printf("El numero mayor es %d", mayor);
    printf("El numero menor es %d", menor);


}


int devuelveMayorPila(Pila * p)
{

    Pila aux;
    inicpila(&aux);

    int mayor;

    if(!pilavacia(p))
    {

        mayor = desapilar(p);

    }

    while(!pilavacia(p))
    {

        if(tope(p) > mayor)
        {

            apilar(&aux,mayor);
            mayor = desapilar(p);
        }
        else
        {

            apilar(&aux, desapilar(p));
        }
    }

    while(!pilavacia(&aux)){
        apilar(p,desapilar(&aux));
    }

    return mayor;

}


int devuelveMayorPilaPorValor(Pila p)
{

    Pila aux;
    inicpila(&aux);

    int mayor;

    if(!pilavacia(&p))
    {

        mayor = desapilar(&p);

    }

    while(!pilavacia(&p))
    {

        if(tope(&p) > mayor)
        {

            apilar(&aux,mayor);
            mayor = desapilar(&p);
        }
        else
        {

            apilar(&aux, desapilar(&p));
        }
    }

    while(!pilavacia(&aux)){
        apilar(&p,desapilar(&aux));
    }

    return mayor;

}







