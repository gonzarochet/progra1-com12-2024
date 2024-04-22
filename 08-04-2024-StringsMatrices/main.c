#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void cargarMatriz(int filas, int columnas, int matrix[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int matrix[filas][columnas]);
float promedio(int filas,int columnas, int matrix[filas][columnas]);
int buscaElementoMatrices(int filas, int columnas, int m[filas][columnas], int dato);

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

    int valor = buscaElementoMatrices(filitas,columnitas,matrix,5);

    if(valor)
    {
        printf("El valor se encuentra en la matriz");
    }
    else
    {
        printf("El valor  NO se encuentra en la matriz");
    }


    int matriz[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };


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


int buscaElementoMatrices(int filas, int columnas, int m[filas][columnas], int dato)
{

    int i = 0;
    int j = 0;
    int flag = 0;

    while(i<filas && flag == 0)
    {
        j = 0;
        while(j<columnas && flag == 0)
        {
            if(m[i][j] == dato)
            {
                flag = 1;
            }
            else
            {
                j++;
            }
        }
        i++;
    }

    return flag;

}



