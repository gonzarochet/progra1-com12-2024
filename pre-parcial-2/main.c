#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

#define AR_ESPECIES "especies.bin"
#define AR_ANIMALES "animales.dat"

typedef struct
{
    int idEspecie;
    int cantEjemplares; // cantidad de animales de esa especie
    char nombreEspecie[30];
} stEspecie;


typedef struct
{
    int nro_identificacion;
    int idEspecie;
    char nombreAnimal[30];
    int poblacion;
} stAnimal;


int idEspecieExiste(char nombreArchivoEspecies[], int idBusqueda);
stAnimal cargarUnAnimal(char nombreArchivoEspecies[]);
int cargarArregloAnimales(stAnimal a[], int v, int dim, char archivoEspecies[]);
void mostrarUnAnimal(stAnimal animal);
void muestraArregloAnimalesRecursivo(stAnimal animales[], int v, int i);



int main()
{
    cargaArchivoEspecieRandom(AR_ESPECIES);
    muestraArchivoEspecies(AR_ESPECIES);

    stAnimal animales[30];
    int vAnimales = 0;

    vAnimales = cargarArregloAnimales(animales,vAnimales,30,AR_ESPECIES);
    muestraArregloAnimalesRecursivo(animales,vAnimales,0);

    stEspecie especies[30];
    int vEspecies = 0;


    subMenuModificaCantidadEjemplaresArchivo(animales,vAnimales,AR_ESPECIES);


    vEspecies = archivoToArregloEspecies(AR_ESPECIES,especies,vEspecies,30);


    muestraArregloEspeciesRecursivo(especies,vEspecies,0);




    return  0;
}



/**
*   1. Hacer una función que cargue un arreglo de animales de 30 registros
* (tantos como quiera el usuario, pero como máximo 30).
* Se debe guardar en alguna variable la cantidad de registros cargados y retornarlo.
* Para esto debe validar que la idEspecie que
* ingrese el usuario exista en el archivo de “especies.dat”.
*
*/

int idEspecieExiste(char nombreArchivoEspecies[], int idBusqueda)
{

    stEspecie esp;

    FILE * archi = fopen(nombreArchivoEspecies,"rb");

    int flag = 0;

    if(archi)
    {
        while(flag == 0 && fread(&esp,sizeof(stEspecie),1,archi) > 0)
        {

            if(esp.idEspecie == idBusqueda)
            {
                flag = 1;
            }

        }
        fclose(archi);
    }


    return flag;
}


stAnimal cargarUnAnimal(char nombreArchivoEspecies[])
{

    stAnimal animal;
    printf("Ingrese nro de identificacion del animal: ");
    scanf("%d", &animal.nro_identificacion);

    int idValido = -1;

    do
    {
        printf("Ingrese idEspecie: ");
        scanf("%d", &idValido);

        if (idEspecieExiste(nombreArchivoEspecies,idValido) == 1)
        {
            animal.idEspecie = idValido;
        }
        else
        {
            printf("Número de especie invalido. Ingrese uno nuevamente\n\n");
            idValido = -1;
        }
    }
    while (idValido == -1);

    printf("Ingrese nombreAnimal: ");
    fflush(stdin);
    gets(animal.nombreAnimal);

    printf("Ingrese poblacion: ");
    scanf("%d", &animal.poblacion);

    return animal;
}


int cargarArregloAnimales(stAnimal a[], int v, int dim, char archivoEspecies[])
{

    int i = v;
    stAnimal animal;
    char opcion = 0;

    while(i<dim && opcion != 27)
    {
        animal = cargarUnAnimal(archivoEspecies);
        a[i] = animal;
        i++;

        printf("Desea seguir cargando animales? ESC para salir. ");
        fflush(stdin);
        opcion = getch();
    }

    return i;


}

/// EXTRA PUNTO 1
void mostrarUnaEspecie(stEspecie e)
{

    printf("\n\n-------------------------\n");
    printf("Id Especie.....%d \n",e.idEspecie);
    printf("Nombre Especie.....%s \n",e.nombreEspecie);
    printf("Cant Ejemplares.....%d \n",e.cantEjemplares);
    printf("------------------------------\n\n");

}

void muestraArchivoEspecies(char nombreArchivo[])
{

    FILE * archi = fopen(nombreArchivo,"rb");
    stEspecie aux;

    if(archi)
    {
        while(fread(&aux,sizeof(stEspecie),1,archi) > 0 )
        {
            mostrarUnaEspecie(aux);
        }
        fclose(archi);
    }

}


/// 2. Hacer una función recursiva que muestre los elementos del arreglo de animales por pantalla.

/// a. mostrar un animal
void mostrarUnAnimal(stAnimal animal)
{

    printf("\n\n-------------------------\n");
    printf("Nro de Identificacion.....%d \n",animal.nro_identificacion);
    printf("Nombre Animal.....%s \n",animal.nombreAnimal);
    printf("Poblacion.....%d \n",animal.poblacion);
    printf("Id Especie.....%d \n",animal.idEspecie);
    printf("------------------------------\n\n");

}

void muestraArregloAnimalesRecursivo(stAnimal animales[], int v, int i)
{

    if(i<v)
    {
        mostrarUnAnimal(animales[i]);
        muestraArregloAnimalesRecursivo(animales,v,i+1);
    }

}


/** 3. Hacer una funcion que pase del archivo a un arreglo de especies aquellas
    especies que su cantidad de ejemplares supere las 2.
    Para esto debera calcular la cantidad de ejemplares de cada
    especie a partir de los elementos del arreglo.
**/



/// 1. Cuenta registros por idEspecie
int cuentaAnimalesPorIdEspecie(stAnimal animales[],int v, int idEspecie)
{
    int cant = 0;
    int i = 0;

    while(i<v)
    {
        if(animales[i].idEspecie == idEspecie)
        {
            cant+=1;
        }
        i++;

    }

    return cant;
}


void buscaModificaArchivoEspecies(char nombreArchivoEspecies[], int idEspecie, int cantNueva)
{

    stEspecie esp;
    FILE * archi = fopen(nombreArchivoEspecies,"r+b");
    int flag = 0;

    if(archi)
    {

        while(flag == 0 && fread(&esp,sizeof(stEspecie),1,archi)> 0)
        {

            if(esp.idEspecie == idEspecie)
            {

                esp.cantEjemplares = cantNueva;
                fseek(archi, -1 * sizeof(stEspecie),SEEK_CUR);
                fwrite(&esp,sizeof(stEspecie),1,archi);
                flag = 1;
            }
        }
        fclose(archi);
    }

}


void subMenuModificaCantidadEjemplaresArchivo(stAnimal animales[], int v, char nombreArchivoEspecies[])
{

    int i = 0;
    int cant = 0;

    while(i < v)
    {
        cant = cuentaAnimalesPorIdEspecie(animales,v, animales[i].idEspecie);
        if(cant > 0)
        {
            buscaModificaArchivoEspecies(nombreArchivoEspecies,animales[i].idEspecie,cant);
        }

        i++;
    }

}


void archivoToArregloEspecies(char nombreArchivoEspecies[], stEspecie arregloEspecies[], int v, int dim)
{

    stEspecie especie;
    FILE * archi = fopen(nombreArchivoEspecies, "rb");
    int i = v;

    if(archi)
    {

        while( i < dim && fread(&especie, sizeof(stEspecie), 1, archi) > 0)
        {
//            mostrarUnaEspecie(especie);
//            system("pause");
            if(especie.cantEjemplares > 2)
            {
                arregloEspecies[i] = especie;
                i++;
            }

        }
        fclose(archi);
    }

    return i;

}


void muestraArregloEspeciesRecursivo(stEspecie arregloEspecies[],int v, int i)
{


    if(i<v)
    {
        mostrarUnaEspecie(arregloEspecies[i]);
        muestraArregloEspeciesRecursivo(arregloEspecies,v,i+1);
    }


}


int sumatoriaPoblacion(stAnimal a[], int v, int i)
{

    int suma;

    if(i == v)
    {
        suma = 0;
    }
    else
    {
        suma = a[i].poblacion + sumatoriaPoblacion(a,v,i+1);
    }

    return suma;

}






















/// FUNCIONES EXTRA
int randomRango(int min, int max)
{
    return  min +  rand()% (max - min +1);
}

stEspecie getEspecieRandom(int i)
{

    stEspecie aux;

    aux.idEspecie = i +1 ;

    switch (aux.idEspecie)
    {

    case 1:
        strcpy(aux.nombreEspecie,"Mamifero");
        break;
    case 2:
        strcpy(aux.nombreEspecie,"Aves");
        break;
    case 3:
        strcpy(aux.nombreEspecie,"Reptiles");
        break;
    case 4:
        strcpy(aux.nombreEspecie,"Anfibios");
        break;
    case 5:
        strcpy(aux.nombreEspecie,"Peces");
        break;

    }

    aux.cantEjemplares = 0;

    return aux;



}


void cargaArchivoEspecieRandom(char nombreArchivo[])
{

    FILE * archi = fopen(nombreArchivo,"wb");
    int i = 0;
    stEspecie aux;

    if(archi)
    {

        while(i<5)
        {
            aux = getEspecieRandom(i);
            fwrite(&aux,sizeof(stEspecie),1,archi);
            i++;

        }

        fclose(archi);
    }

}


/// 1. Cantidad de especies
int cantRegistrosArchivos(char nombreArchivo[], int tamanio)
{

    FILE * archi = fopen(nombreArchivo,"rb");
    int cant = 0;

    if(archi)
    {
        fseek(archi,0,SEEK_END);
        cant  = ftell(archi) / tamanio;
        fclose(archi);
    }

    return cant;
}
