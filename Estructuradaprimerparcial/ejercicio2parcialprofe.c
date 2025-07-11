/*Ejercicio2. Se desea realizar un pgroama en lenguaje C que permita actualizar el precio y/o
modificar la descrpcion de un producto en forma individual
La empresa trabaja con 150 productos con la siguiente estructura
 -Codigo(entero)
 -Precio (float)
 -Descripcion(de hasta 60 caracteres)
Se solicita ingresar dichos dactos en un vector de estructuras
Luego se ingresaran por teclado codigos de productos,de los cuales se quiere modificar algun dato
o ambos hasta ungresar un codigo cero. En caso de existir el codigo en el vector,se consultara que dato
se quiere modificar.Si es el precio,se ingresara el nuevo importe validando que sea mayor a cero, si se desea cambiar la descripcion
se ingresara la nueva cadena validando que no supere los 60 caracteres.
Adicionalmente se solicita informar el procentaje de codigos rechazados.Se lo considera rechazado cuando el codig a buscar
no existe en el vector.
Para la busqueda del codigo en el vector de estructuras,utilizar una funcio*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int codigo;
    float precio;
    char descripcion[61];
}sProductos;

void Ingreso(sProductos [],int);

int main ()
{
    sProductos vector[150];
    Ingreso(vector,150);
}

void Ingreso(sProductos vector[],int ce)
{
    int i=0,largo;
    float aux;
    for ( i = 0; i < ce; i++)
    {
        printf("Ingrese el codigo del producto: ");
        scanf("%d",&vector[i].codigo);
        printf("Ingrese el precio: ");
        scanf("%f",&aux);
        if (aux>0.00)
        {
            vector[i].precio=aux;
            fflush(stdin);
            printf("\nIngrese la descripcion del producto: ");
            fgets(vector[i].descripcion,61,stdin);
        }
    }
    
}