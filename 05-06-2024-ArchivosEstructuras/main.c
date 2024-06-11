#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "alumno.h"
#include "nota.h"

#define AR_ALUMNOS "alumnos.dat"
#define AR_NOTA "notas.dat"


int archivoToArregloAlumnos(char nombrearchivo[], stAlumno a[], int v, int dim);
int archivoToArregloNotas(char nombreArchivoNotas[], stNota notas[],int vNotas,int dim);
void muestraArregloAlumnos(stAlumno a[], int v);
void muestraArregloNotas(stNota a[], int v);
int cantElementosArchivoBis(char nombreArchivo[], int tamanio);
void arregloAlArchivoAlumnos(stAlumno a[], int v, char nombreArchivo[]);
void arregloAlArchivoNotas(stNota notas[],int vNotas,char nombreArchivoNotas[]);
int buscaAlumnoPosicionLegajoEnArreglo(stAlumno a[], int v, int legajoAux);

void subMenuModificarUsuario(stAlumno alumnos[],int vAlumnos);
void subMenuAgregarNotasAUsuarios(stAlumno alumnos[], int vAlumnos, stNota notas[],int * vNotas);
stAlumno subMenuCampoUsuarioAModificar(stAlumno anterior);

int main()
{

    menu(AR_ALUMNOS,AR_NOTA);

    return 0;
}


void listadoOpciones()
{
    printf("\n--------------------------------------------\n");
    printf("1. Crear un alumno.\n");
    printf("2. Mostrar listado de alumnos.\n");
    printf("3. Modificar un alumno en el arreglo.\n");
    printf("4. Modificar un alumno desde el archivo\n");
    printf("5. Agregar una nota.\n");
    printf("6. Mostrar listado de notas.\n");
    printf("7. Guardar cambios en el archivo.\n");
    printf("8. Salir.\n");

    printf("\n--------------------------------------------\n");
}


void menu(char nombreArchivoAlumnos[], char nombreArchivoNotas[])
{
    int option = 0;
    stAlumno aux;

    stAlumno alumnos[100];
    int vAlumnos = 0;
    static int idAlumno = 0;

    stNota notas[100];
    int vNotas = 0;


    vAlumnos = archivoToArregloAlumnos(nombreArchivoAlumnos,alumnos,vAlumnos,100);
    vNotas = archivoToArregloNotas(nombreArchivoNotas,notas,vNotas,100);

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
            printf(" 4. Modificar un alumno desde el Archivo \n");
            subMenuModificarAlumnoDesdeArchivo(nombreArchivoAlumnos);
            break;

        case 5:
            printf("\n 5. Agregar Nota al Arreglo\n");
            subMenuAgregarNotasAUsuarios(alumnos,vAlumnos,notas,&vNotas);
            break;
        case 6:
            printf("\n 6. Listar notas desde el arreglo \n");
            muestraArregloNotas(notas,vNotas);
            break;
        case 7:
            printf("7. Guardar cambios en el archivo.\n");
            arregloAlArchivoAlumnos(alumnos,vAlumnos,nombreArchivoAlumnos);
            arregloAlArchivoNotas(notas,vNotas,nombreArchivoNotas);
            break;
        case 8:
            printf("8. Salir.\n");
            break;
        default:
            printf("Opcion invalida. Ingrese nuevamente");
        }
        printf("\nPresione una tecla para continuar\n");
        getch();
        system("cls");
    }
    while(option != 8);


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

int archivoToArregloNotas(char nombreArchivoNotas[], stNota notas[],int vNotas,int dim)
{

    int cant = cantElementosArchivoBis(nombreArchivoNotas,sizeof(stNota));
    int total = vNotas + cant;

    FILE * archi = fopen(nombreArchivoNotas,"rb");

    if(archi && total <= dim)
    {
        while(fread(&notas[vNotas],sizeof(stNota),1,archi) > 0)
        {
            vNotas++;
        }
        fclose(archi);
    }

    return vNotas;


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

void arregloAlArchivoNotas(stNota notas[],int vNotas,char nombreArchivoNotas[])
{

    FILE * archi = fopen(nombreArchivoNotas,"wb");

    if(archi)
    {
        fwrite(notas,sizeof(stNota),vNotas,archi);
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

void muestraArregloNotas(stNota a[], int v)
{
    for(int i = 0; i<v; i++)
    {
        mostrarUnaNota(a[i]);
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


/// Notas

void subMenuAgregarNotasAUsuarios(stAlumno alumnos[], int vAlumnos, stNota notas[],int * vNotas)
{

    int legajoAlumno = -1 ;
    int posAlumno = -1;

    int validosNotas = *vNotas;

    stAlumno alumnoAux;
    stNota notaAux;

    printf("\n Ingresa el legajo del alumno al cual queres agregarle una nota: ");
    scanf("%d", &legajoAlumno);

    posAlumno = buscaAlumnoPosicionLegajoEnArreglo(alumnos,vAlumnos,legajoAlumno);

    if(posAlumno > -1 )
    {

        alumnoAux = alumnos[posAlumno];
        notaAux = crearUnaNota();
        notaAux.legajoAlumno = alumnoAux.legajo;

        if(vNotas > 0)
        {
            notaAux.idNota = validosNotas;
        }
        else
        {
            notaAux.idNota = 0;

        }

        notas[validosNotas] = notaAux;
        validosNotas++;

        *vNotas = validosNotas;

        printf("\n Se agrego una nota al arreglo. Acuerse de guardar los cambios en el archivo. \n");

    }
    else
    {
        printf("\n No se encontro el alumno con ese legajo. Intente con otro legajo. \n");

    }
}


int buscarAlumnoEnArchivoPorLegajo(char nombreArchivoAlumnos[], int legajo)
{

    int pos = -1;
    int i = 0;
    stAlumno a;

    FILE * archi = fopen(nombreArchivoAlumnos,"rb");

    if(archi)
    {
        while(pos == -1 && fread(&a,sizeof(stAlumno),1,archi) > 0)
        {
            if(a.legajo == legajo)
            {
                pos = i;
            }
            i++;
        }
        fclose(archi);
    }

    return pos;

}


void modificarAlumnoEnArchivo(char nombreArchivoAlumnos[], int pos)
{

    FILE * archi = fopen(nombreArchivoAlumnos,"r+b");
        // me permite retroceder al momento de la escritura.
        // No sucede eso con a+b que siempre escribe al final.
    stAlumno aux;

    if(archi)
    {
        fseek(archi,0,SEEK_SET);
        fseek(archi,sizeof(stAlumno)* pos, SEEK_CUR);
        fread(&aux,sizeof(stAlumno),1,archi);

        aux = subMenuCampoUsuarioAModificar(aux);

        fseek(archi,  (-1) * sizeof(stAlumno), SEEK_CUR);

        fwrite(&aux,sizeof(stAlumno),1,archi);

        fclose(archi);
    }else{
        printf("No se abrio correctamente\n");
    }

}




void subMenuModificarAlumnoDesdeArchivo(char nombreArchivoAlumnos[])
{

    int legajoAlumno;
    int posEnArchi = -1;
    int opcion2 = 0;
    stAlumno nuevo;

    printf("\n Ingrese el legajo del usuario a modificar \n ");
    scanf("%d",&legajoAlumno);

    posEnArchi = buscarAlumnoEnArchivoPorLegajo(nombreArchivoAlumnos,legajoAlumno);


    if(posEnArchi > - 1)
    {
        modificarAlumnoEnArchivo(nombreArchivoAlumnos,posEnArchi);
    }
    else
    {

        printf("\n No existe alumno con ese legajo");
    }

}

stAlumno subMenuCampoUsuarioAModificar(stAlumno anterior)
{

    int option2 = 0;

    printf("Cual campo queres modificar?\n");
    printf("1. Nombre y Apellido\n");
    printf("2. Anio \n");
    printf("3. Cancelar");

    scanf("%d",&option2);

    switch(option2)
    {

    case 1:
        printf("Ingrese el nuevo nombre y Apellido\n");
        fflush(stdin);
        gets(anterior.nombreYapellido);
        printf("Se modifico correctamente \n");
        break;

    case 2:
        printf("Ingrese el nuevo Anio \n");
        gets(anterior.anio);
        printf("Se modifico correctamente\n");
        break;
    case 3:
        break;
    default:
        printf("No existe esa opción \n");
    }

    return anterior;

}












/// Funciones con estructuras

