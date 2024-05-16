#include "alumno.h"


stAlumno cargaUnAlumno(){

    stAlumno alumno;

    char aux[100];

    printf("\n Ingrese el nro de legajo: ");
    scanf("%d",&alumno.legajo);

    printf("\n Ingrese el dni:  ");
    fflush(stdin);
    scanf("%s",aux);
    strcpy(alumno.dni,aux);

    printf("\n Ingrese el nombre:  ");
    fflush(stdin);
    scanf("%s",aux);
    strcpy(alumno.nombre,aux);

    printf("\n Ingrese el apellido:  ");
    fflush(stdin);
    scanf("%s",aux);
    strcpy(alumno.apellido,aux);

    printf("\n Ingrese el dia de nacimiento: ");
    scanf("%d",&alumno.dia);

    printf("\n Ingrese el mes de nacimiento: ");
    scanf("%d",&alumno.mes);

    printf("\n Ingrese el dia de nacimiento: ");
    scanf("%d",&alumno.anio);

    printf("\n Ingrese el genero ('m' , 'f', 'x' ) ");
    fflush(stdin);
    scanf("%c",&alumno.genero);

//    alumno.domicilio = cargaUnaDireccion();

    return alumno;
}

void mostrarUnAlumno(stAlumno alumno){

    printf("\n---------------------------------\n");
    printf("Legajo:.................. %d \n",alumno.legajo);
    printf("Nombre:............... %s \n",alumno.nombre);
    printf("Apellido:............. %s \n",alumno.apellido);
    printf("DNI:.................. %s \n",alumno.dni);
    printf("Fecha Nacimiento:..... %d - %d - %d \n",alumno.dia, alumno.mes, alumno.anio);
    printf("Genero:.................. %c \n",alumno.genero);
    printf("<<<< DOMICILIO-INFO >>>>:");
//    mostrarUnaDireccion(alumno.domicilio);
    printf("\n---------------------------------\n");

}


int randomRango(int min, int max){
    return  min +  rand()% (max - min +1);
}


int getDia(){
    return randomRango(1,31);
}

int getMes(){
    return randomRango(1,12);
}

int getAnio(){
    return randomRango(1900,2024);
}

int getLegajo(){
    return randomRango(1,999999);
}


void setApellidoRandom(char apellido[]){

    char arreglosApellido[][30] = {"Rojas", "Alvarez",
                "Pintos" , "Gomez", "Garcia", "Romero"};

    strcpy(apellido,arreglosApellido[randomRango(0,sizeof(arreglosApellido)/30)]);
}


void setNombreRandom(char nombre[]){
    char arregloNombres[][30] = {"Alejandro", "Bruno", "Carlos", "Daniel",
    "Eduardo", "Fernando", "Gabriel", "Hugo", "Ignacio", "Javier", "Alicia",
    "Beatriz", "Carla", "Diana", "Elena", "Fernanda", "Gabriela", "Helena",
    "Isabel", "Julieta"};

    strcpy(nombre, arregloNombres[randomRango(0,sizeof(arregloNombres)/30)]);
}

void setDni(char dni[]){
   int dniE =  randomRango(1000000,99999999);
   itoa(dniE,dni,10);
}

char getGenero(){
    char array[3] = {'m','f', 'x'};
    return array [randomRango(0,2)];
}



stAlumno cargaRandomAlumno(){

    stAlumno alumno;

    alumno.legajo = getLegajo();
    setNombreRandom(alumno.nombre);
    setApellidoRandom(alumno.apellido);
    setDni(alumno.dni);
    alumno.dia = getDia();
    alumno.mes = getMes();
    alumno.anio = getAnio();
    alumno.genero = getGenero();


    return alumno;

}












