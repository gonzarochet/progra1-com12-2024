#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>



int main()
{
  srand(time(NULL));
    /* Ejercicio 1, 2 y 3 - Contar, sumar, promedio"




    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    int cantidadDada = rand()%10 + 1;
    int numero = 0;

    int sumatoria = 0;
    int contador  = 0;
    float promedio = 0;

    for(int i = 0; i < cantidadDada; i++)
    {
       numero = rand()% 10 + 1;
       apilar(&dada,numero);
    }

    mostrar(&dada);

    while(!pilavacia(&dada))
    {
       contador = contador + 1;
       sumatoria = sumatoria + tope(&dada);
       apilar(&aux,desapilar(&dada));
    }

    promedio = (float) sumatoria /  contador;

    printf("La cantidad de elementos es %d, la sumatoria da %d, y el promedio es %.2f",contador,sumatoria,promedio);

    */



    /* Ejercicio 7 - 8. Determinar si un elemento existe en la pila. Mantener los elementos en el mismo orden"

    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    int numero = 0;
    int numeroABuscar;
    int flag = 0 ;

    for(int i = 0; i <  8; i++)
    {
        numero = rand()% 10 + 1;
        apilar(&dada,numero);
    }

    mostrar(&dada);

    printf("Ingrese el numero a buscar: ");
    scanf("%d",&numeroABuscar);

    while(!pilavacia(&dada) && flag == 0)
    {
        if(tope(&dada) == numeroABuscar)
        {
            flag = 1;
            // borrar elemento: apilar(&descarte, desapilar(&dada);
        }
        else
        {
            apilar(&aux,desapilar(&dada));
        }
    }

    while(!pilavacia(&aux)){
        apilar(&dada,desapilar(&aux));
    }


    if(flag == 0){
        printf("El numero NO existe en la pila");
    }else{
        printf("El numero existe en la pila");
    }

    mostrar(&dada);


    */


    /* Ejercicio 4 - Encontrar el menor (solo pilas)
    Pila dada, aux, menor;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);

    int numero = 0;

    for(int i = 0; i <  8; i++)
    {
        numero = rand()% 10 + 1;
        apilar(&dada,numero);
    }

    mostrar(&dada);

    if(!pilavacia(&dada)){
        apilar(&menor, desapilar(&dada));
    }

    while(!pilavacia(&dada)){
        if(tope(&dada) < tope(&menor)){
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(&dada));
        }else{
            apilar(&aux, desapilar(&dada));
        }
    }

    printf("El menor elemento de la pila dada es: %d", tope(&menor));

    */

    /* Ejercicio 6 - Ordenación X Selección

    Pila dada, aux, menor;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);

    int numero = 0;

    for(int i = 0; i <  8; i++)
    {
        numero = rand()% 10 + 1;
        apilar(&dada,numero);
    }


    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&menor, desapilar(&dada));

        while(!pilavacia(&dada))
        {
            if(tope(&dada) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }
            else
            {
                apilar(&aux, desapilar(&dada));
            }
        }

        while(!pilavacia(&aux))
        {
            apilar(&dada,desapilar(&aux));
        }


    }
    mostrar(&menor);
    */










    return 0;
}
