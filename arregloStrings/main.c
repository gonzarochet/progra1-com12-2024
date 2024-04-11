#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int cargarArregloStrings1(int cantidadCaracteres, char arreglo[][cantidadCaracteres], int cantidadStrings);
void mostrarArrayStrings(char arrayString[][20],int cantElem);
int findLowerPosition(char arrayString[][20],int cantElem,int posInit);

int main()
{
    int cantStrings = 20; // cantidad de strings
    int cantCaracteres = 100; // caracteres para cada string

    char arrayOfStrings [cantStrings][cantCaracteres];
    int v = 0;

    /*

    strcpy(arrayOfStrings[0],"Jorge");
    strcpy(arrayOfStrings[1],"Abel");
    strcpy(arrayOfStrings[2],"Rojas");
    strcpy(arrayOfStrings[3],"Pintos");
    strcpy(arrayOfStrings[4],"Sergio");
    strcpy(arrayOfStrings[5],"Gallegillo");
    strcpy(arrayOfStrings[6],"Chaquenio");
    strcpy(arrayOfStrings[7],"Palavecino");

    */


    v = cargarArregloStrings1(cantCaracteres,arrayOfStrings,cantStrings);
    printf("el valor de v es %d",v);
    mostrarArrayStrings(arrayOfStrings, v);




    return 0;
}

int cargarArregloStrings1(int cantidadCaracteres, char arreglo[][cantidadCaracteres], int cantidadStrings) {
    int i;
    char temp[cantidadCaracteres];

    for (i = 0; i < 5; i++) {
        printf("Ingrese el string %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);
        // Eliminar el carácter de nueva línea al final de la entrada
        //temp[strcspn(temp, "\n")] = 0;
        strcpy(arreglo[i], temp);
    }

    return i;
}



int cargarArregloStrings(int cantStrings, int dimCaracteresStrings, char arregloString[dimCaracteresStrings][cantStrings], int v)
{

    int i = v;
    char option = 's';
    char string[dimCaracteresStrings];

    while(i < cantStrings && option != 27)
    {
        printf("Ingrese una palabra\n");
        fgets(arregloString[i], dimCaracteresStrings, stdin);
        i++;

        printf("Desea continuar agregando datos?");
        fflush(stdin);
        option = getch();


        system("cls");

    }


    return i;

}

void mostrarArrayStrings(char arrayString[][20],int cantElem)
{
    for(int i = 0; i<cantElem; i++)
    {
        printf("\n %s",arrayString[i]);

    }
    printf("\n----------------");
}

/*
int insertOrder(char arrayString[][20],int cantElem,char stringToOrder[])
{
    int i = cantElem - 1;
    int flag = 0;
    while(i>=0 && (strcmp(arrayString[i],stringToOrder)>0))
    {
        strcpy(arrayString[i+1],arrayString[i]);
        i--;
    }
    strcpy(arrayString[i+1],stringToOrder);

    return cantElem+1;

}

void insertionSort(char arrayString[][20],int cantElem)
{
    char stringToOrder[20];
    for(int i = 1; i<cantElem; i++)
    {
        strcpy(stringToOrder, arrayString[i]);
        insertOrder(arrayString, i, stringToOrder);
    }
}


*/
int findLowerPosition(char arrayString[][20],int cantElem,int posInit)
{

    int position = posInit;
    char aux[20];

    strcpy(aux,arrayString[position]);

    for(int i = posInit + 1; i <cantElem; i++)
    {
        if(strcmp(arrayString[i],aux)<0)
        {
            strcpy(aux,arrayString[i]);
            position = i;
        }
    }

    return position;

}

/*
void selectionSort(char arrayString[][20],int cantElem)
{
    int i = 0;
    int posLower;
    char aux[20];
    while(i<cantElem-1)
    {
        posLower = findLowerPosition(arrayString,cantElem,i);
        strcpy(aux,arrayString[i]);
        strcpy(arrayString[i],arrayString[posLower]);
        strcpy(arrayString[posLower],aux);
        i++;
    }
}

*/
