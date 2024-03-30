#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPilaRandom(Pila *p);
int devuelveMayorPila(Pila * p);
int devuelveMayorPilaPorValor(Pila p);
void cargarPilaManual(Pila * p);
void muestraPila(Pila p);
void pasarPila(Pila * origen, Pila * destino);
void pasarPila(Pila * origen, Pila * destino);
void pasarPilaPares(Pila * origen, Pila * destino);
void pasarDatosMismoOrden(Pila * origen, Pila * destino);
int buscaMenor (Pila * p);
void ordenacionXSeleccion(Pila * origen, Pila * ordenada);
void insertarPilaOrdenada(Pila * ordenada, int dato);
void ordenacionXInsercion(Pila * desordenada, Pila * ordenada);



int main()
{
    Pila dada, pilita;
    inicpila(&dada);
    inicpila(&pilita);
    cargarPilaManual(&dada);
    printf("\n La pila dada inicio: \n");
    mostrar(&dada);

//    pasarPilaPares(&dada,&pilita);
//
//    printf("\n La pila pilita con los datos: \n");
//    muestraPila(pilita);
//
//    printf("\nLa pila dada vacia: \n");
//    muestraPila(dada);


    //int menor;
    //menor = buscaMenor(&dada);

    //mostrar(&dada);

    //printf("El menor elemento de la pila era %d", menor);

   // ordenacionXSeleccion(&dada, &pilita);
    ordenacionXInsercion(&dada, &pilita);

    printf("\nLa pila dada despues de la ordenacion : \n");
    mostrar(&dada);


    printf("\n La pila pilita con los datos ordenados: \n");
    mostrar(&pilita);



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


void cargarPilaManual(Pila * p)
{

    char opcion = 's';
    int valor;


    do
    {
        printf("Ingrese un valor\n");
        scanf("%d",&valor);
        apilar(p,valor);

        printf("Quiere continuar? Presione n para salir");
        fflush(stdin);
        scanf("%c",&opcion);

    }
    while(opcion != 'n');


}

void muestraPila(Pila p)
{
    Pila aux;
    inicpila(&aux);
    int par = 0;

    printf("\nBase-------------------------------------Tope\n");
    while(!pilavacia(&p))
    {


        printf("%d |",tope(&p));

        apilar(&aux,desapilar(&p));
        par++;
    }

}


void pasarPila(Pila * origen, Pila * destino)
{

    while(!pilavacia(origen))
    {
        apilar(destino,desapilar(origen));
    }

}

void pasarPilaPares(Pila * origen, Pila * destino)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen))
    {
        if(tope(origen)%2==0)
        {
            apilar(destino,desapilar(origen));
        }
        else
        {
            apilar(&aux,desapilar(origen));
        }

    }

}

void pasarDatosMismoOrden(Pila * origen, Pila * destino){
    Pila aux;
    inicpila(&aux);

    pasarPila(origen,&aux);
    pasarPila(&aux,destino);

}



int buscaMenor (Pila * p){

    Pila aux;
    inicpila(&aux);

    int valorMenor;

    if(!pilavacia(p)){
        valorMenor = desapilar(p);
    }

    while(!pilavacia(p)){
        if(tope(p) < valorMenor){
            apilar(&aux,valorMenor);
            valorMenor = desapilar(p);
        }else{
            apilar(&aux, desapilar(p));

        }
    }

    pasarPila(&aux,p);

   return valorMenor;

}



void ordenacionXSeleccion(Pila * origen, Pila * ordenada){

    int valorMenor;

    while(!pilavacia(origen)){
        valorMenor = buscaMenor(origen);
        apilar(ordenada,valorMenor);
    }

}



void insertarPilaOrdenada(Pila * ordenada, int dato){

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(ordenada) && tope(ordenada) < dato){
        apilar(&aux,desapilar(ordenada));
    }
    apilar(ordenada,dato);

    pasarPila(&aux,ordenada);

}

void ordenacionXInsercion(Pila * desordenada, Pila * ordenada){

    while(!pilavacia(desordenada)){
        insertarPilaOrdenada(ordenada,desapilar(desordenada));
    }

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

    while(!pilavacia(&aux))
    {
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


    return mayor;

}




