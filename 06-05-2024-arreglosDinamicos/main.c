#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int num;
    int *p = NULL;
    int i;

    puts("Numero de elementos:");
    scanf("%d", &num);

   // p = (int *) calloc(num, sizeof(int)); Tambien es valido.
    p = (int *) malloc(sizeof(int) * num);
    if (!p) // p == NULL;
    {
        puts("\nError de memoria");
        exit(1);
    }
    else
        printf("\nHe reservado en %p", p);

    srand(time(NULL));

    for (i = 0 ; i < num ; i++ )
    {
        p[i] = rand() % 100;
    }

    puts("\nNumeros:");
    for (i = 0 ; i < num ; i++)
        printf("%d ", p[i]);

    free(p);
    p = NULL;


    return 0;
}
int * reservarDevolviendo(int *ptr, int num){
	// La funcion declara que devuelve un puntero.

	ptr = (int *) malloc(sizeof(int) * num);
	if (ptr == NULL){
		puts("\nError de memoria");
		exit(1);
	} else
		printf("\nHe reservado en %p", ptr);

	return ptr;
}

void reservar(int **ptr, int num){
	// La funcion declara un doble puntero

	// Acceso al contenido del puntero para reservar el bloque de memoria.
	*ptr = (int *) malloc(sizeof(int) * num);
	if (*ptr == NULL){
		puts("\nError de memoria");
		exit(1);
	} else
		printf("\nHe reservado en %p", *ptr);
}

void cargarArregloDinamicoRandom(int *ptr, int num){
	int i;

	srand(time(NULL));
	for (i = 0 ; i < num ; i++ ){
		ptr[i] = rand() % 100;
	}

}

void imprimir(int *ptr, int num){
	int i;

	puts("\nNumeros:");
	for (i = 0 ; i < num ; i++)
		printf("%d ", ptr[i]);
}

void liberar(int **ptr){
	free(*ptr);
	*ptr = NULL;
}
