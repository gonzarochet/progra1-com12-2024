#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"


void mostrarArreglo(int arreglo[], int v);
float promedioArreglo(int arreglo[], int v);
void arregloToPila(int arreglo[], int v, Pila * p, float promedio);
int buscarElementoMenorPila(Pila p);

int main()
{
    printf("Hello world!\n");

    int arreglo [24];
    int vArreglo = 0;
    float promedio = 0.0;
    Pila p;
    inicpila(&p);

    int menorPila;
    int mayorPosArreglo;

    vArreglo = cargarArreglo(arreglo,vArreglo,24);
    mostrarArreglo(arreglo,vArreglo);

    promedio = promedioArreglo(arreglo,vArreglo);
    printf("El promedio es %.2f",promedio);

    arregloToPila(arreglo,vArreglo,&p,promedio);
    mostrar(&p);

    menorPila = buscarElementoMenorPila(p);
    printf("\nEl menor elemento en la pila es %d", menorPila);

    mayorPosArreglo = buscaPosMayor(arreglo,vArreglo);
    mostrarArreglo(arreglo,vArreglo);

    printf("\nLa posicion del mayor elemento es %d",mayorPosArreglo);


    return 0;
}


int cargarArreglo(int arreglo[], int v, int dim)
{

    int i = v;
    char option = 0;
    int temp;

    while( i < dim && option != 27 )
    {

        printf("Ingrese una temperatura\n");
        scanf("%d",&temp);

        if(temp < 60 && temp > -45)
        {
            arreglo[i] = temp;
            i++;
        }
        else
        {
            printf("El dato no es valido \n ");
        }

        printf("\nQuiere seguir cargando datos?");
        fflush(stdin);
        option = getch();
        system("cls");
    }

    return i;
}



void mostrarArreglo(int arreglo[], int v)
{

    for(int i = 0; i<v; i++)
    {
        if(i%7 == 0)
        {
            printf("\n") ;
        }
        printf("%d |",arreglo[i]);
    }


}



int sumaElementosArreglo(int arreglo[], int v)
{

    int suma = 0;
    for(int i = 0; i<v; i++)
    {
        suma = suma + arreglo[i];
    }

    return suma;
}


float promedioArreglo(int arreglo[], int v)
{
    return (float) sumaElementosArreglo(arreglo,v) / v;

}


void arregloToPila(int arreglo[], int v, Pila * p, float promedio)
{

    for(int i = 0; i < v; i++)
    {
        if(arreglo[i] < promedio)
        {
            apilar(p,arreglo[i]);
        }
    }
}

int buscarElementoMenorPila(Pila p)
{
    Pila aux;
    inicpila(&aux);

    int menor;

    if(!pilavacia(&p))
    {
        menor = desapilar(&p);
    }

    while(!pilavacia(&p))
    {
        if(tope(&p) < menor)
        {
            apilar(&aux,menor);
            menor = desapilar(&p);
        }
        else
        {
            apilar(&aux, desapilar(&p));
        }
    }

    return menor;

}

int buscaPosMayor(int arreglo[], int v){

    int posMayor = -1;

    if(v>0){
        posMayor = 0;
    }

    for(int i = 1; i<v; i++){

        if(arreglo[posMayor] < arreglo[i]){
            posMayor = i;
        }

    }
    return posMayor;
}






