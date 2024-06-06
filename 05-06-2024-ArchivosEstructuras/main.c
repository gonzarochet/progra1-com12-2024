#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define AR_ALUMNOS "alumnos.dat"

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

stAlumno crearUnAlumno();
void mostrarUnAlumno(stAlumno a);
int archivoToArregloAlumnos(char nombrearchivo[], stAlumno a[], int v, int dim);
void muestraArregloAlumnos(stAlumno a[], int v);
int cantElementosArchivoBis(char nombreArchivo[], int tamanio);
void arregloAlArchivoAlumnos(stAlumno a[], int v, char nombreArchivo[]);
int buscaAlumnoPosicionLegajoEnArreglo(stAlumno a[], int v, int legajoAux);

void subMenuModificarUsuario(stAlumno alumnos[],int vAlumnos);

int main()
{

    menu(AR_ALUMNOS);

    return 0;
}

stAlumno crearUnAlumno()
{
    stAlumno a;
    char aux[100];

    printf("\n Ingrese el nombre:  \n");
    fflush(stdin);
    gets(a.nombreYapellido);

    printf("Ingrese la edad \n");
    scanf("%d",&a.edad);

    printf("Ingrese el anio \n");
    scanf("%d",&a.anio);

    return a;

}


void mostrarUnAlumno(stAlumno a)
{
    printf("\n---------------------------------\n");
    printf("Legajo:.................. %d \n",a.legajo);
    printf("Nombre y Apellido:....... %s \n",a.nombreYapellido);
    printf("Edad:.................. %d \n",a.edad);
    printf("Anio:.................. %d \n",a.anio);
    printf("\n--------------------------------------------\n");
}

void listadoOpciones()
{
    printf("\n--------------------------------------------\n");
    printf("1. Crear un alumno.\n");
    printf("2. Mostrar listado de alumnos.\n");
    printf("3. Modificar un alumno.\n");
    printf("4. Guardar cambios en el archivo.\n");
    printf("5. Guardar cambios y salir.\n");
    printf("\n--------------------------------------------\n");
}


void menu(char nombreArchivoAlumnos[])
{
    int option = 0;
    stAlumno aux;

    stAlumno alumnos[100];
    int vAlumnos = 0;
    static int idAlumno = 0;


    vAlumnos = archivoToArregloAlumnos(nombreArchivoAlumnos,alumnos,vAlumnos,100);

    do
    {
        listadoOpciones();
        scanf("%d", &option);

        system("cls");

        switch(option)
        {


        case 1:

            printf("\n 1. Crear un alumno:  \n");
            aux = crearUnAlumno();

            if(vAlumnos > 0)
            {
                aux.legajo= vAlumnos;
            }
            else
            {
                aux.legajo = 0;
            }

            alumnos[vAlumnos] = aux;
            vAlumnos++;

            printf("Alumno creado correctamente. Recuerde Guardarlo en el archivo.");


            break;

        case 2:
            printf("\n 2. Mostrar Listado:  \n");
            muestraArregloAlumnos(alumnos,vAlumnos);
            break;
        case 3:
            printf("\n 3. Modificar un alumno desde el Arreglo:  \n");

            subMenuModificarUsuario(alumnos,vAlumnos);

            break;
        case 4:
            printf("4. Guardar cambios en el archivo.\n");
            arregloAlArchivoAlumnos(alumnos,vAlumnos,nombreArchivoAlumnos);
            break;
        case 5:
            printf("5. Guardar cambios en el archivo y salir.\n");
            break;
        default:
            printf("Opcion invalida. Ingrese nuevamente");
        }
        printf("\nPresione una tecla para continuar\n");
        getch();
        system("cls");
    }
    while(option != 5);


}


void subMenuModificarUsuario(stAlumno alumnos[],int vAlumnos)
{

    int legajoAux;
    int option2;
    int pos = -1;

    printf("¿Cual alumno queres modificar? Escribi el legajo\n");
    scanf("%d",&legajoAux);


    pos = buscaAlumnoPosicionLegajoEnArreglo(alumnos,vAlumnos,legajoAux);

    if(pos > -1)
    {
        do
        {
            printf("Cual campo queres modificar?\n");
            printf("1. Nombre y Apellido\n");
            printf("2. Anio?\n");
            printf("3. Cancelar");

            scanf("%d",&option2);

            switch(option2)
            {

            case 1:
                printf("Ingrese el nuevo nombre y Apellido\n");
                fflush(stdin);
                gets(alumnos[pos].nombreYapellido);
                printf("Se modifico correctamente \n");
                break;

            case 2:
                printf("Ingrese el nuevo Anio \n");
                gets(alumnos[pos].anio);
                printf("Se modifico correctamente\n");
                break;
            case 3:

                break;
            default:
                printf("No existe esa opción \n");
            }

        }
        while(option2 != 3);

    }
    else
    {

        printf("\n No existe alumno con ese legajo");
    }


}

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

int archivoToArregloAlumnos(char nombrearchivo[], stAlumno a[], int v, int dim)
{

    int cant = cantElementosArchivoBis(nombrearchivo,sizeof(stAlumno));
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

void arregloAlArchivoAlumnos(stAlumno a[], int v, char nombreArchivo[])
{

    FILE * archi = fopen(nombreArchivo,"wb");

    if(archi)
    {
        fwrite(a,sizeof(stAlumno),v,archi);
        fclose(archi);
    }
}


void muestraArregloAlumnos(stAlumno a[], int v)
{
    for(int i = 0; i<v; i++)
    {
        mostrarUnAlumno(a[i]);
    }
}


int buscaAlumnoPosicionLegajoEnArreglo(stAlumno a[], int v, int legajoAux)
{

    int pos = -1;
    int i = 0;

    while(i < v && pos == -1 )
    {
        if(a[i].legajo == legajoAux)
        {
            pos = i;
        }
        i++;
    }


    return pos;
}




/// Funciones con estructuras

