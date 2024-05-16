#include "pilaAlumno.h"


void inicPilaAlumnos(PilaAlumnos * p)
{

    p->dim = 75; // (*p).dim = 50;
    p->a = (stAlumno*) malloc(p->dim * sizeof(stAlumno));
    p->v = 0;
}

void apilarPilaAlumnos(PilaAlumnos * p, stAlumno dato)
{

    int nuevaDim;

    if(p->v == p->dim)
    {
        nuevaDim = p->dim + 50;
        p->a = (stAlumno*) realloc(p->a,sizeof(stAlumno)*nuevaDim);
        p->dim = nuevaDim;
    }

    p->a[p->v] = dato;
    p->v += 1;

}

stAlumno topePilaAlumnos(PilaAlumnos * p)
{
    stAlumno aux;
    aux.legajo = -1;

    if(p->v > 0)
    {
        aux = p->a[p->v-1];
    }

    return aux;
}

int pilaAlumnosVacia(PilaAlumnos * p)
{
    int flag;

    if(p->v  == 0)
    {
        flag = 1;
    }
    else
    {
        flag = 0;

    }

    return flag;
}

int pilaAlumnosVaciaTernario(PilaAlumnos * p){
    return (p->v == 0) ? 1 : 0;
}

int pilaAlumnosVaciaPro(PilaAlumnos * p){
    return (p->v == 0);
}

stAlumno desapilarPilaAlumnos(PilaAlumnos * p){

    stAlumno aux = p->a[p->v-1];
    p->v--;
    return aux;
}

void mostrarPilaAlumnos(PilaAlumnos * p){

    printf("\n................. <<<<<< BASE >>>>>>.............................\n\n");
    for(int i = 0;  i < p->v; i++){
        mostrarUnAlumno(p->a[i]);
    }
    printf("\n................. <<<<<< TOPE >>>>>>.............................\n\n");
}

void leerPilaAlumnos(PilaAlumnos * p, char mensaje[]);





