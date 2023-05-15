/** Tomás Valero - Comisión 4 - DNI 41.332.715 */

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargarParesImpares(Pila *pila1, int arreglo[], int dim);
int pasarPrimerosDiez(Pila pila1, int arreglo[]);
int cargarAutos(int autos[], float km[], int dim);
int validarPosicion(int arr[], int validos, int pos);
void mostrarArreglo(int arreglo[], int validos);
void mostrarArregloFloat(float arreglo[], int validos);
void mostrarPosicion(int arr[], int validos);
void recorrerPila(Pila *pila1);


int main()
{
    int dim1 = 5;
    int dim2 = 9;
    int autos[dim1];
    float kilometros[dim1];
    int miArreglo[dim1];
    int arregloVacio[dim2];
    int validos;
    int flag;
    int opc;
    Pila dada;
    inicpila(&dada);

    printf("\n1- INCISOS DEL 1 AL 3 \n");
    printf("\n2- INCISOS 4 y 5 \n");
    fflush(stdin);
    scanf("%d", &opc);
    switch(opc)
    {
    case 1:
        validos = cargarParesImpares(&dada, miArreglo, dim1);
        printf("\nARREGLO: \n");
        mostrarArreglo(miArreglo, validos);
        printf("\nPILA CON FUNCION: \n");
        recorrerPila(&dada);
        printf("\nPILA CON MOSTRAR: \n");
        mostrar(&dada);

        printf("\nPASAMOS LOS PRIMEROS DIEZ A UN ARREGLO VACIO: \n");
        flag = pasarPrimerosDiez(dada, arregloVacio);
        printf("\nArreglo vacio: \n");
        mostrarArreglo(arregloVacio, dim2);
        if(flag == 0)
        {
            printf("\n\nEl arreglo tenia menos de diez o diez\n\n");
        }
        else
        {
            printf("\n\nEl arreglo tenia mas de diez\n\n");
        }
        break;
    case 2:
        validos = cargarAutos(autos, kilometros, dim1);
        mostrarArreglo(autos, validos);
        mostrarArregloFloat(kilometros, validos);
        printf("Autos cargados: %d\n", validos);
        break;
    default:
        printf("\nOpcion incorrecta\n");
        break;
    }



}

/** Inciso 1. */
int cargarParesImpares(Pila *pila1, int arreglo[], int dim)
{
    char opc = 's';
    int valor;
    int i = 0;

    while(opc == 's')
    {
        printf("\nIngrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &valor);
        if(valor % 2 == 1 && i < dim+1)
        {
            arreglo[i] = valor;
            i++;
            if(i == dim+1)
            {
                printf("\nEl arreglo ahora esta lleno.\n");
            }
        }
        else if (valor % 2 == 0)
        {
            apilar(pila1, valor);
        }
        else
        {
            printf("\nEl arreglo esta lleno!\n");
        }
        printf("\nIngrese 's' para seguir cargando valores.\n");
        fflush(stdin);
        scanf("%c", &opc);
    }
    return i;
}

/** Función para mostrar y comprobar el funcionamiento de mi arreglo. */
void mostrarArreglo(int arreglo[], int validos)
{
    int i = 0;
    for(i; i<validos; i++)
    {
        printf(" | %i ", arreglo[i]);
    }
    printf("|\n");
}

/** Función para mostrar y comprobar el funcionamiento de mi arreglo float. */
void mostrarArregloFloat(float arreglo[], int validos)
{
    int i = 0;
    for(i; i<validos; i++)
    {
        printf(" | %.3f ", arreglo[i]);
    }
    printf("|\n");
}

/** Inciso 2. */
void recorrerPila(Pila *pila1)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila1))
    {
        apilar(&aux, desapilar(pila1));
    }

    printf("\nBase .............................................. Tope\n\n");
    printf("|");
    while(!pilavacia(&aux))
    {
        printf(" %d |", tope(&aux));
        apilar(pila1, desapilar(&aux));
    }
    printf("\n\nBase .............................................. Tope\n\n");
}

/** Inciso 3. */
int pasarPrimerosDiez(Pila pila1, int arreglo[])
{
    int flag = 0;
    int i = 0;
    Pila aux;
    inicpila(&aux);
    while(i < 10 && !pilavacia(&pila1))
    {
        arreglo[i] = tope(&pila1);
        apilar(&aux, desapilar(&pila1));
        i++;
    }
    while(i < 10)
    {
        arreglo[i] = 0;
        i++;
    }

    if(!pilavacia(&pila1))
    {
        flag = 1;
    }

    return flag;
}

/** Inciso 4. */
int cargarAutos(int autos[], float km[], int dim)
{
    int i = 0;
    int fecha;
    float kilometros;
    char opc;
    do
    {
        printf("Ingrese el año del auto %i: ", i+1);
        fflush(stdin);
        scanf("%i", &fecha);
        printf("Ingrese los kilometros del auto %i: ", i+1);
        autos[i] = fecha;
        fflush(stdin);
        scanf("%f", &kilometros);
        km[i] = kilometros;
        i++;

        printf("\nIngrese 's' para seguir cargando valores.\n");
        fflush(stdin);
        scanf("%c", &opc);
    }
    while(opc == 's' && i <= dim);

    return i;
}

/** Inciso 5a. */
int validarPosicion(int arr[], int validos, int pos)
{
    int flag = 0;
    if(pos < validos)
    {
        flag = 1;
    }
    return flag;
}

/** Inciso 5b. */
void mostrarPosicion(int arr[], int validos)
{
    int pos;
    printf("\nQue posicion desea mostrar?\n");
    fflush(stdin);
    scanf("%i", &pos);

    if(validarPosicion(arr, validos, pos) == 1)
    {
        printf("\nPosicion n° %i del arreglo:\n");
        printf("%i", arr[pos]);
    }
    else
    {
        printf("\nNo hay existe esta posicion\n");
    }
}
