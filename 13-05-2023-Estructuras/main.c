#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"
#include <time.h>
#include "pilaAlumno.h"
#include <windows.h>

void cargarAlumnosAlArchivo(char nombreArchivo[]);
void mostrarDesdeElArchivo(char nombreArchivo[]);
void muestraArregloAlumnos(stAlumno a[], int v);
int cantElementosArchivoBis(char nombreArchivo[], int tamanio);
stAlumno buscarAlumnoArchivo(char nombreArchivo[], int legajo);
stAlumno * buscaAlumnoArchivoPuntero(char nombreArchivo[], int legajo);
int archivoToArreglo(char nombrearchivo[], stAlumno a[], int v, int dim);
void arregloToArchivo(stAlumno a[], int v, char nombrearchivo[]);

#define AR_ALUMNOS "alumnos.dat"
#define AR_ALUMNOS_FINAL "alumnitos.dat"


int main()
{
    srand(time(NULL));

    //cargarAlumnosAlArchivo(AR_ALUMNOS);
   // printf("\n\n<<<<<<<<<<<<<<< LISTADO DESDE EL ARCHIVO >>>>>>>>>>>><<<<<<<>>>><\n\n");
    //mostrarDesdeElArchivo(AR_ALUMNOS);

    stAlumno arregloAlumnos[100];
    int vArreglo = 0;
    vArreglo = archivoToArreglo(AR_ALUMNOS,arregloAlumnos,vArreglo,100);
    printf("\n\n<<<<<<<<<<<<<<< LISTADO DESDE EL ARREGLO >>>>>>>>>>>><<<<<<<>>>><\n\n");
    muestraArregloAlumnos(arregloAlumnos,vArreglo);


    arregloToArchivo(arregloAlumnos,vArreglo,AR_ALUMNOS_FINAL);
    printf("\n\n<<<<<<<<<<<<<<< LISTADO DESDE EL ARCHIVO >>>>>>>>>>>><<<<<<<>>>><\n\n");
    mostrarDesdeElArchivo(AR_ALUMNOS_FINAL);
//     int cant = cantElementosArchivo(AR_ALUMNOS);
//     printf("\n\n<<<<<<<<<<<<<<< CANT VALORES EN ARCHIVO: %d >>>>>>>>>>>><<<<<<<>>>><\n\n",cant);
//
//     int cant2 = cantElementosArchivoBis(AR_ALUMNOS,sizeof(stAlumno));
//     printf("\n\n<<<<<<<<<<<<<<< CANT 2  VALORES EN ARCHIVO: %d >>>>>>>>>>>><<<<<<<>>>><\n\n",cant2);


//    stAlumno * pAlumno = NULL;
//
//    stAlumno a;
//
//    a = buscarAlumnoArchivo(AR_ALUMNOS,5);
//
//    printf("\n\n<<<<<<<<<<<<<<< BUSQUEDA >>>>>>>>>>>><<<<<<<>>>><\n\n");
//    if(a.legajo >= 0){
//        mostrarUnAlumno(a);
//    }else{
//        printf("No existe el alumno con ese legajo");
//    }

    stAlumno * pAlumno = NULL;
    stAlumno alumno;

    pAlumno = buscaAlumnoArchivoPuntero(AR_ALUMNOS,18542);

    printf("\n\n<<<<<<<<<<<<<<< BUSQUEDA >>>>>>>>>>>><<<<<<<>>>><\n\n");
    if(pAlumno != NULL)
    {
        alumno = *pAlumno;
        mostrarUnAlumno(alumno);
    }
    else
    {
        printf("No existe el alumno con ese legajo");
    }



    return 0;
}

void cargarAlumnosAlArchivo(char nombreArchivo[])
{

    char opcion = 0;
    stAlumno a;
    int cant = 0;

    FILE * archi = fopen(nombreArchivo,"ab");

    if(archi != NULL)   /// if(archi)
    {

        do
        {
            a = cargaRandomAlumno();
            cant = fwrite(&a,sizeof(stAlumno),1,archi);
            printf("\nFue escrito %d con exito\n",cant);

            printf("Quiere seguir cargando datos al archivo? Esc para salir\n");
            fflush(stdin);
            opcion = getch();

        }
        while(opcion != 27);

        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir");
    }

}


void mostrarDesdeElArchivo(char nombreArchivo[])
{

    stAlumno a;

    FILE * archi = fopen(nombreArchivo,"rb");

    if(archi)
    {

        while(fread(&a,sizeof(stAlumno),1,archi) > 0)
        {
            mostrarUnAlumno(a);
        }

        fclose(archi);
    }
    else
    {

        printf("No se pudo abrir");
    }

}

void muestraArregloAlumnos(stAlumno a[], int v){
    for(int i = 0; i<v; i++){
        mostrarUnAlumno(a[i]);
    }
}

/// Busqueda de un alumno en un archivo
stAlumno buscarAlumnoArchivo(char nombreArchivo[], int legajo)
{

    stAlumno aux, actual;
    aux.legajo = -1;

    int flag = 0;

    FILE * archi = fopen(nombreArchivo,"rb");

    if(archi != NULL)
    {

        while(flag == 0 && fread(&actual,sizeof(stAlumno),1,archi)> 0)
        {
            if(legajo == actual.legajo)
            {
                aux = actual;
                flag = 1;
            }
        }

        fclose(archi);

    }

    return aux;

}


stAlumno * buscaAlumnoArchivoPuntero(char nombreArchivo[], int legajo)
{

    stAlumno * a = NULL;
    stAlumno alumno;

    FILE * archi = fopen(nombreArchivo,"rb");

    if(archi)
    {
        while(a == NULL && fread(&alumno,sizeof(stAlumno),1,archi)>0)
        {
            if(alumno.legajo == legajo)
                a = &alumno;
        }

        fclose(archi);
    }

    return a;
}


/// del arreglo al archivo
void arregloToArchivo(stAlumno a[], int v, char nombrearchivo[])
{
    FILE * archi = fopen(nombrearchivo,"ab");

    if(archi){
        fwrite(a,sizeof(stAlumno),v,archi);
        fclose(archi);
    }

}





/// del archivo al arreglo
int archivoToArreglo(char nombrearchivo[], stAlumno a[], int v, int dim)
{

    int cant = cantElementosArchivo(nombrearchivo);
    int total = v + cant;

    FILE * archi = fopen(nombrearchivo,"rb");

    if( archi && total <= dim)
    {
        while(fread(&a[v],sizeof(stAlumno),1,archi) > 0)
        {
            v++;
        }
        fclose(archi);
    }

    return v;

}


/** \brief Cantidad de Alumnos en un Archivo
 *
 * \param char[] : string con el nombre del archivo
 * \param
 * \return cantidad de elementos del archivo
 *
 */
int cantElementosArchivo(char nombreArchivo[])
{

    FILE * archi = fopen(nombreArchivo,"rb");
    int cant = 0;

    if(archi)
    {
        fseek(archi, 0, SEEK_END);
        cant = ftell(archi)/sizeof(stAlumno);
        fclose(archi);
    }

    return cant;

}

/** \brief Cantidad de elementos en un archivo
 *
 * \param char[] : string con el nombre del archivo
 * \param int : el tamanio de la estructura del archivo
 * \return cantidad de elementos del archivo
 *
 */
int cantElementosArchivoBis(char nombreArchivo[], int tamanio)
{

    FILE * archi = fopen(nombreArchivo,"rb");
    int cant = 0;

    if(archi)
    {
        fseek(archi, 0, SEEK_END);
        cant = ftell(archi)/tamanio;
        fclose(archi);
    }

    return cant;

}















