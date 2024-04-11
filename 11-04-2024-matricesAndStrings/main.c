#include <stdio.h>
#include <stdlib.h>


void cargarMatriz(int filas, int columnas, int matrix[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int matrix[filas][columnas]);
float promedio(int filas,int columnas, int matrix[filas][columnas]);

int main()
{
    printf("Matrices!\n");
    srand(time(NULL));

    int filas = 2;
    int columnas = 2;
    int matrix[filas][columnas];

    cargarMatriz(filas,columnas,matrix);
    mostrarMatriz(filas,columnas,matrix);
    float avg = promedio(filas,columnas,matrix);

    printf("El promedio es %.2f",avg);




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
