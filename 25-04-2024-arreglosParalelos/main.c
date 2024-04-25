#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int cargaAlumnoP(int c, char nombres[][c], int notas[], int v, int dim);
void muestraAlumnoP(int c, char nombres[][c], int notas[],int v);

void muestraMatrizUsuario(int cantFilas, int m[cantFilas][3], int AP[]);

const int DIMCARACTERES = 30;
const int DIM = 20;

int main()
{

//    char nombres[DIM][DIMCARACTERES];
//    int notas[20] = {0};
//
//    int validosAlumnos = 0;
//
//    validosAlumnos = cargaAlumnoP(DIMCARACTERES, nombres,notas,validosAlumnos,DIM);
//    muestraAlumnoP(DIMCARACTERES,nombres,notas,validosAlumnos);


    int matriz[3][3];
    int cantF = 0;

    int aP[3] = {0};

    cantF = cargaMatrizUsuario(3,3,matriz,aP);
    muestraMatrizUsuario(cantF,matriz,aP);


    return 0;
}

int cargaAlumnoP(int c, char nombres[][c], int notas[], int v, int dim){
    char option = 0;
    int indice = v;
    char n[c];

    while(indice < dim && option != 27){

        printf("Ingrese el nombre del alumno\n");
        fflush(stdin);
        gets(n);
        strcpy(nombres[indice],n);
        // nombres[indice] = "jorge"; NO SE PUEDE HACER

        printf("Ingrese la nota\n");
        scanf("%d",&notas[indice]);

        indice++;


        printf("Quiere seguir cargando ? \n" );
        option = getch();

        system("cls");
    }

    return indice;
}


void muestraAlumnoP(int c, char nombres[][c], int notas[],int v){

    for(int i = 0; i < v; i++){
        printf("\n-----------------------------------------\n");
        printf("Nombre: ......... %s\n",nombres[i]);
        printf("Nota: ......... %d\n",notas[i]);
    }
    printf("\n-----------------------------------------\n");

}


int cargaMatrizUsuario(int dFilas, int dCol, int m[dFilas][dCol], int AP[]){

    char opF = 0;
    char opC = 0;
    int indiceF = 0;
    int indiceC = 0;


    while(indiceF < dFilas && opF != 27){

        indiceC = 0;
        opC = 0;

        while(indiceC < dCol && opC != 27){

            printf("Ingresa un dato: \n");
            scanf("%d", &m[indiceF][indiceC]);
            AP[indiceF] = AP[indiceF] + 1;

            indiceC++;

            printf("Quiere seguir cargando datos en la columna %d, fila %d. ESC para salir\n",indiceC,indiceF);
            opC = getch();
        }
        indiceF++;

        printf("Quiere seguir cargando datos en la fila %d. ESC para salir\n",indiceF);
        opF = getch();

    }

    return indiceF;

}

void muestraMatrizUsuario(int cantFilas, int m[cantFilas][3], int AP[]){

    int i = 0;
    int j = 0;

    for(i = 0; i<cantFilas; i++){

        j = 0;
        for(j = 0; j < AP[i]; j++){
               printf("%d ", m[i][j]);
        }
        printf("\n");

    }

}









