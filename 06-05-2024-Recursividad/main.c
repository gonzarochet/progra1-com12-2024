#include <stdio.h>
#include <stdlib.h>


void muestraArregloRecursivo(int arreglo[], int v, int i);
int cantElementosRecursivoCondicion(int a[],int v, int i, int condicion);
int cantElementosRecursivoCondicionImplicito(int a[],int v, int i, int condicion);

int main()
{
    int a[5] = {10,20,35,14,5};

    muestraArregloRecursivo(a,5,0);

    int suma = sumaRecursivaImplicito(a,5,0);

    printf("\n la suma de los elementos es %d \n",suma);


    int cant = cantElementosRecursivoCondicion(a,5,0,10);
    printf("\n la cantidad de elementos mayores a 10 es %d \n", cant);





    return 0;
}


void muestraArregloRecursivo(int arreglo[], int v, int i)
{

    if(i < v)
    {
        muestraArregloRecursivo(arreglo,v,i+1);
        printf("%d |",arreglo[i]);
    }

}


int sumaRecursivaEnArreglo(int arreglo[], int v, int i)
{

    int sumatoria;

    if(i == v)
    {
        sumatoria = 0;
    }
    else
    {
        sumatoria = arreglo[i] + sumaRecursivaEnArreglo(arreglo,v,i+1);
    }

    return sumatoria;
}



int sumaRecursivaImplicito(int arreglo[], int v, int i)
{

    int suma = 0;

    if(i<v)
    {

        suma = arreglo[i] + sumaRecursivaImplicito(arreglo,v, i+1);

    }

    return suma;
}


int cantElementosRecursivoCondicion(int a[],int v, int i, int condicion)
{

    int cant;

    if(i == v)
    {
        cant = 0;
    }
    else
    {

        if(a[i] > condicion)
        {
            cant = 1 + cantElementosRecursivoCondicion(a,v,i+1,condicion);
        }
        else
        {

            cant = cantElementosRecursivoCondicion(a,v,i+1,condicion);

        }


    }
    return cant;

}

int cantElementosRecursivoCondicionImplicito(int a[],int v, int i, int condicion)
{

    int cant = 0;

    if(i<v)
    {

        if(a[i] > condicion)
        {
            cant = 1 + cantElementosRecursivoCondicion(a,v,i+1,condicion);
        }
        else
        {
            cant = cantElementosRecursivoCondicion(a,v, i+1, condicion);
        }


    }

    return cant;

}



int sumaElementosRecursivoCondicion(int a[],int v, int i, int cond)
{

    int suma;

    if(i == v)
    {
        suma = 0;
    }
    else
    {

        if(a[i] < cond)
        {

            suma = a[i] + sumaElementosRecursivoCondicion(a,v,i+1,cond);
        }
        else
        {

            suma = 0 + sumaElementosRecursivoCondicion(a,v,i+1, cond);

        }


    }


    return suma;



}

float promedio(int a[], int v){

    return (float) sumaRecursivaEnArreglo(a,v,0) / v;

}












