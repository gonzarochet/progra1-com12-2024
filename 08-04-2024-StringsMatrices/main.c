#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void cargarMatriz(int filas, int columnas, int matrix[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int matrix[filas][columnas]);
float promedio(int filas,int columnas, int matrix[filas][columnas]);

int main()
{
    printf("Hello world!\n");
    srand(time(NULL));

    int filitas = 3;
    int columnitas = 4;

    int matrix[filitas][columnitas];

    cargarMatriz(filitas,columnitas,matrix);
    mostrarMatriz(filitas,columnitas,matrix);
    //float avg = promedio(filas,columnas,matrix);


   // printf("El promedio es %.2f",avg);




    return 0;
}

void cargarMatriz(int filas, int columnas, int matrix[filas][columnas])
{

    int j = 0;
    for(int i = 0; i<filas; i++)
    {
        for(j = 0; j<columnas; j++)
        {
            matrix[i][j] = rand()%10+1;
        }
    }
}

void mostrarMatriz(int filas, int columnas, int matrix[filas][columnas])
{
    int j = 0;
    for(int i = 0; i<filas; i++)
    {
        for(j = 0; j<columnas; j++)
        {
            printf("  %d ", matrix[i][j]);

        }
        printf("\n");
    }
}


float promedio(int filas,int columnas, int matrix[filas][columnas])
{
    int j =0;
    float avg = 0.0;
    for(int i = 0; i<filas; i++)
    {
        for(j = 0; j<columnas; j++)
        {
            avg+=(float)matrix[i][j];
        }

    }
        return (float)avg/(filas*columnas);
}
