#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define AR_DEUDORES "deudores.dat"
#define AR_ACREDORES "acredores.dat"

typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    int edad;
    float saldo;
} stCliente;

int existeCliente(stCliente arrClientes[], int v, int idBuscar);
int validaEdad(int min, int max, int edad);
stCliente cargaUnCliente();
int cargaClientesEnArreglo(stCliente arrClientes[], int v, int dim);
void mostrarUnCliente(stCliente cliente);
void mostrarClientesRecursivo(stCliente arrClientes[], int v, int i);
float sumaRecursivoSaldosClientes(stCliente arrClientes[], int v, int i);
void arregloToArchivos(stCliente arrClientes[], int v, char nombreArchivoDeu[], char nombreArchivoAcr[]);
void muestraArchivo(char nombreArchivo[], int saldoTope);
int cuentaElementosArchivo(char nombreArchivo [], int tamanio);
float sumaSaldosArchivo(char nombreArchivo[]);
void balanceTotalBanco(char nombreArchivoDeu[], char nombreArchivoAcr[]);



int main()
{
    stCliente arregloClientes[50];
    int vArregloClientes = 0;

    //vArregloClientes = cargaClientesEnArreglo(arregloClientes,vArregloClientes,50);
    printf("Clientes en el archivo\n");
    // mostrarClientesRecursivo(arregloClientes,vArregloClientes,0);

    float suma = sumaRecursivoSaldosClientes(arregloClientes,vArregloClientes,0);
    printf("La suma de los saldos es %f \n",suma);

    arregloToArchivos(arregloClientes,vArregloClientes,AR_DEUDORES,AR_ACREDORES);
    printf("Archivo de deudores: \n");
    muestraArchivo(AR_DEUDORES,-9999999);
    printf("Archivo de acreedores: \n");
    muestraArchivo(AR_ACREDORES,0);


    balanceTotalBanco(AR_DEUDORES, AR_ACREDORES);



    return 0;
}

int existeCliente(stCliente arrClientes[], int v, int idBuscar)
{

    int i = 0;
    int flag = 0;

    while(i < v && flag == 0)
    {
        if(arrClientes[i].idCliente == idBuscar)
        {
            flag = 1;
        }
        i++;
    }

    return flag;
}

int validaEdad(int min, int max, int edad)
{
    return (edad >= min && edad <= max) ? 1 : 0;
}


stCliente cargaUnCliente()
{

    stCliente cliente;

    printf("\n Ingrese un nombre \n");
    fflush(stdin);
    gets(cliente.nombre);

    printf("Ingrese un apellido\n");
    fflush(stdin);
    gets(cliente.apellido);

    printf("Ingrese un saldo \n");
    scanf("%f",&cliente.saldo);

    do
    {
        printf("Ingrese la edad \n");
        scanf("%d",&cliente.edad);
    }
    while(validaEdad(18,12,cliente.edad));


    return cliente;
}


int cargaClientesEnArreglo(stCliente arrClientes[], int v, int dim)
{
    stCliente aux;
    int idCliente;
    char option = 0;
    int flag = 0;

    while(v < dim && option != 27 )
    {
        aux = cargaUnCliente();

        do
        {
            printf("Ingresá un id para el cliente: \n");
            scanf("%d",&idCliente);

            flag = existeCliente(arrClientes,v,idCliente);

            if(flag==0)
            {
                aux.idCliente = idCliente;
                arrClientes[v] = aux;
            }
            else
            {
                printf("El id ingresado esta repetido\n");
            }

        }
        while(flag == 1);
        v++;

        printf("Quiere seguir cargando datos?");
        fflush(stdin);
        option = getch();

    }

    return v;
}


/// 2. Mostrar recursivo
void mostrarUnCliente(stCliente cliente)
{
    printf("\n --------------------------------------------- \n");
    printf("ID del Cliente: %d\n", cliente.idCliente);
    printf("Nombre: %s\n", cliente.nombre);
    printf("Apellido: %s\n", cliente.apellido);
    printf("Edad: %d\n", cliente.edad);
    printf("Saldo: %.2f\n", cliente.saldo);
    printf("\n --------------------------------------------- \n");
}


void mostrarClientesRecursivo(stCliente arrClientes[], int v, int i)
{

    if(i<v)
    {
        mostrarUnCliente(arrClientes[i]);
        mostrarClientesRecursivo(arrClientes, v, i+1);
    }

}

///  3. Suma recursiva saldos
float sumaRecursivoSaldosClientes(stCliente arrClientes[], int v, int i)
{
    int suma;

    if(i == v)
    {
        suma = 0;
    }
    else
    {
        suma = arrClientes[i].saldo + sumaRecursivoSaldosClientes(arrClientes, v, i+1);
    }

    return suma;
}

/// 4.
void arregloToArchivos(stCliente arrClientes[], int v, char nombreArchivoDeu[], char nombreArchivoAcr[])
{
    FILE * archiDeu = fopen(nombreArchivoDeu, "ab");
    FILE * archiAcr = fopen(nombreArchivoAcr, "ab");

    stCliente cliente;


    if(archiDeu && archiAcr)
    {
        int i = 0;
        while(i<v)
        {
            cliente = arrClientes[i];

            if(cliente.saldo < 0)
            {
                fwrite(&cliente, sizeof(stCliente), 1, archiDeu);
            }
            else
            {
                fwrite(&cliente, sizeof(stCliente), 1, archiAcr);
            }
            i++;
        }

        fclose(archiAcr);
        fclose(archiDeu);

    }

}

/// 5.
void muestraArchivo(char nombreArchivo[], int saldoTope)
{
    FILE * archi = fopen(nombreArchivo, "rb");

    stCliente cliente;

    if(archi)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archi) > 0)
        {

            if(cliente.saldo > saldoTope)
            {
                mostrarUnCliente(cliente);
            }

        }

        fclose(archi);
    }

}


/// 6.
int cuentaElementosArchivo(char nombreArchivo [], int tamanio)
{
    FILE * archi = fopen(nombreArchivo, "rb");

    int cant = 0;

    if(archi)
    {

        fseek(archi, 0, SEEK_END);

        cant = ftell(archi)/tamanio;


    }

    return cant;
}

/// 7.
float sumaSaldosArchivo(char nombreArchivo[])
{
    FILE * archi = fopen(nombreArchivo, "rb");

    float suma  = 0;

    stCliente cliente;

    if(archi)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archi) > 0)
        {

            suma = suma + cliente.saldo;

        }

        fclose(archi);
    }

    return suma;

}


void balanceTotalBanco(char nombreArchivoDeu[], char nombreArchivoAcr[])
{
    FILE * archiDeu = fopen(nombreArchivoDeu, "rb");
    FILE * archiAcr = fopen(nombreArchivoAcr, "rb");

    stCliente cliente;

    int clientesDeu = cuentaElementosArchivo(nombreArchivoDeu,sizeof(stCliente));
    int clientesAcr = cuentaElementosArchivo(nombreArchivoAcr,sizeof(stCliente));

    int sumaClientes = clientesDeu + clientesAcr;

    float porcentajeDeu = (float)(clientesDeu * 100) / sumaClientes;
    float porcentajeAcr = (float)(clientesAcr * 100) / sumaClientes;

    float balance = sumaSaldosArchivo(archiDeu) + sumaSaldosArchivo(archiAcr);

    printf("\n El porcentaje de deudores es: %.2f", porcentajeDeu);
    printf("\n El porcentaje de acredores es: %.2f", porcentajeAcr);
    printf("\n El balance total del banco es : %.2f", balance);

}




