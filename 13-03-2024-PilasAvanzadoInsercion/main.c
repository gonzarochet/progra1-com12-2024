#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>


/* 5. Insertar un elemento en una pila
ordenada de menor (tope) a mayor (base)
de forma tal que se conserve el orden.
(sin variables, solo pilas) */



int main()
{

    /// Ejercicio 5 - Insertar un elemento en una pila ordenada de menor (tope) a mayor (base)
    /*
        srand(time(NULL));
        Pila dada, aux;
        inicpila(&dada);
        inicpila(&aux);

        apilar(&dada, -1);
        apilar(&dada, 2);
        apilar(&dada, 4);
        apilar(&dada, 6);
        apilar(&dada, 8);

        mostrar(&dada);

        int elementoAIngresar = 5;

        while(!pilavacia(&dada) && tope(&dada) > elementoAIngresar)
        {
            apilar(&aux,desapilar(&dada));
        }

        apilar(&dada,elementoAIngresar);

        while(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }

        mostrar(&dada);


    */

    /// EJERCICIO 12 - Ordenamiento por insercion
    /*
        // Ejercicio 12 - Ordenamiento por inserción

        srand(time(NULL));

        Pila dada, aux, ordenadaInsercion;
        inicpila(&dada);
        inicpila(&aux);
        inicpila(&ordenadaInsercion);


        for(int i = 0; i < 10; i++){
            apilar(&dada, rand()%10 +1 );
        }

        mostrar(&dada);

        int dato;

        while(!pilavacia(&dada))
        {
            dato = desapilar(&dada);


            while(!pilavacia(&ordenadaInsercion) && tope(&ordenadaInsercion) < dato)
            {
                apilar(&aux,desapilar(&ordenadaInsercion));
            }

            apilar(&ordenadaInsercion,dato);

            while(!pilavacia(&aux))
            {
                apilar(&ordenadaInsercion, desapilar(&aux));
            }

        }

        mostrar(&ordenadaInsercion);
       // mostrar(&dada);
     */


    /// Ejercicio 6 - Averiguar si una pila es capicua o no

    Pila dada, copia, aux, aux1, aux2;
    inicpila(&dada);
    inicpila(&copia);
    inicpila(&aux);
    inicpila(&aux1);
    inicpila(&aux2);

    apilar(&dada, 5);
    apilar(&dada, 2);
    apilar(&dada, 1);
    apilar(&dada, 2);
    apilar(&dada, 5);
    apilar(&dada, 6);


    while(!pilavacia(&dada))
    {
        apilar(&copia, tope(&dada));
        apilar(&aux, desapilar(&dada));
    }

    while(!pilavacia(&aux))
    {
        apilar(&dada,desapilar(&aux));
    }

    while(!pilavacia(&dada) && !pilavacia(&copia) && tope(&dada) == tope(&copia))
    {
        apilar(&aux2, desapilar(&dada));
        apilar(&aux1, desapilar(&copia));
    }

    if(pilavacia(&dada) && pilavacia(&copia))
    {
        printf("la pila es capicua");
    }
    else
    {
        printf("la pila no es capicua");
    }


    return 0;
}
