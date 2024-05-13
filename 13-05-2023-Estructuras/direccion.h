#ifndef DIRECCION_H_INCLUDED
#define DIRECCION_H_INCLUDED


typedef struct{
    char calle[50];
    int altura;
    int cp;
    char ciudad[100];
    char localidad[50];
    char pais[100];
} stDireccion;

stDireccion cargaUnaDireccion();
void mostrarUnaDireccion();

#endif // DIRECCION_H_INCLUDED
