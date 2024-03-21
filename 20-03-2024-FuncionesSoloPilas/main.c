#include <stdio.h>
#include <stdlib.h>

void cargarPilaRandom(Pila *p);
int devuelveMayorPila(Pila * p);
int devuelveMayorPilaPorValor(Pila p);


int main()
{
    printf("Hello world!\n");
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


    return mayor;

}
