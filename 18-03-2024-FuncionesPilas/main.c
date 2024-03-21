#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

void cargarPilaRandom10Valores(Pila *p);
void intercambio ( int * a, int * b);
void intercambioSinAuxiliar(int * a, int * b);
void muestraMayorMenor(int nro1, int nro2, int nro3);
int devuelveMayorPila(Pila * p);
int devuelveMayorPilaPorValor(Pila p);

int sumaEnterosPositivos(int numero);
void cambiarSignoNumeroPositivo (int * nro);

void menu();
void menuOpciones();


int main()
{
    srand(time(NULL));

    menu();


    return 0;
}

void menuOpciones()
{
    printf("\n1. Intercambio con variable auxiliar \n");
    printf("2. Intercambio sin variable auxiliar \n");
    printf("3. Muestra Mayor y Menor \n");
    printf("4. Suma elementos desde el nro ingresado hasta el cero \n");
    printf("5. Funcion que recibe un un número positivo entero y cambie su signo a negativo.\n");
}


void menu()
{

    char opcion;

    int nro1;
    int nro2;
    int nro3;
    int total;

    do
    {
        menuOpciones();

        printf("\n\n Ingrese una opcion \n\n");
        fflush(stdin);
        scanf("%c",&opcion);

        switch(opcion)
        {

        case 49:
            printf("\n Ingrese un valor para el nro1\n");
            scanf("%d",&nro1);

            printf("\n Ingrese un valor para el nro2\n");
            scanf("%d",&nro2);

            intercambio(&nro1,&nro2);

            printf("Despues del intercambio\n");

            printf("El valor de nro 1 es %d \n", nro1);
            printf("El valor de nro 2 es %d \n", nro2);

            break;

        case 50:

            printf("\nIngrese un valor para el nro1\n");
            scanf("%d",&nro1);

            printf("\nIngrese un valor para el nro2\n");
            scanf("%d",&nro2);

            intercambioSinAuxiliar(&nro1,&nro2);

            printf("Despues del intercambio\n");

            printf( "El valor de nro 1 es %d \n", nro1);
            printf("El valor de nro 2 es %d \n", nro2);

            break;

        case 51:

            printf("\nIngrese un valor para el nro1\n");
            scanf("%d",&nro1);

            printf("\nIngrese un valor para el nro2\n");
            scanf("%d",&nro2);

            printf("\nIngrese un valor para el nro2\n");
            scanf("%d",&nro3);

            muestraMayorMenor(nro1,nro2,nro3);

            break;


        case 52:
            printf("\n Ingrese un valor para hacer el calculo\n");
            scanf("%d",&nro1);

            total = sumaEnterosPositivos(nro1);

            printf("\n\n El total es %d \n\n",total);

            break;

        case 53:

            printf("\nIngrese un valor  positivo para pasarlo a negativo\n");
            scanf("%d",&nro1);

            cambiarSignoNumeroPositivo(&nro1);

            printf("\n\n El numero es %d\n\n",nro1);

            break;

        default:
            break;
        }

        printf("Quiere continuar? Presione n para salir. Cualquier tecla para continuar\n");
        fflush(stdin);
        scanf("%c",&opcion);

        system("cls");

    }
    while ((opcion != 'n') && (opcion != 'N'));



}



/// 0. Funcion de Intercambio - Ejemplo powerpoint
void intercambio ( int * a, int * b)
{
    int aux;

    aux = *a ;
    *a = *b;
    *b = aux;

}

void intercambioSinAuxiliar(int * a, int * b)
{

    *a =  *a + *b;
    *b =  *a - *b;
    *a =   *a - *b;

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


    printf("\nEl numero mayor es %d\n", mayor);
    printf("El numero menor es %d\n", menor);


}


/// 3. Diseñe una función que reciba un número entero N y
/// realice la suma de los números enteros positivos
/// menores que N y lo retorne. N es un  dato ingresado por el usuario en el main.

int sumaEnterosPositivos(int numero)
{

    int totalSuma = 0;

    for( int i = numero; i>0; i--)
    {
        totalSuma = totalSuma + i;
    }


    return totalSuma;
}


/** \brief Funcion que cambia de valor a un numero positivo.
*
* \param *num
*
*/
void cambiarSignoNumeroPositivo (int * nro)
{
    int aux = *nro;

    if( aux > 0)
    {
        *nro = (aux * (-1));
    }
    else if( aux == 0)
    {
        printf("El numero ya es 0 ");

    }
    else
    {
        printf("El numero ya es negativo");

    }

}

/// Funciones con pilas
void cargarPilaRandom(Pila *p)
{

    int nro = 0;


    for(int i = 0; i < 10 ; i++)
    {
        nro = rand()%10 +1;
        apilar(p,nro);
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







