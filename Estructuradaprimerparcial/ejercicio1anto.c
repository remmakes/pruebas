/*Se desea estudiar los importes de las ventas realizadas durante el día por una empresa donde trabajan 15 vendedores y se comercializan 20 artículos.
Para tal fin, al finalizar el horario laboral, se nos suministran diversas planillas donde figura por cada venta de un determinado artículo:
el número de vendedor que realizó la venta, el número de artículo, la cantidad vendida y el precio unitario de dicho artículo.
. Número de vendedor (de 1 a 15) validar el ingreso con una función
. Número de artículo (de 1 a 20) validar el ingreso con la misma función
. Cantidad vendida (int)
. Precio Unitario (float)
Dichos datos, se ingresarán por teclado en forma desordenada, hasta la lectura de un número de vendedor 0 (cero). Se puede repetir durante el día,
la venta de un artículo para un mismo vendedor, y no hay necesariamente venta de todos los artículos.
Desarrollar la codificación en lenguaje C que permita:
a) Informar el número de vendedor / número de artículo que realizó la mayor recaudación (el mayor es único)
b) Informar el total de recaudación por número de artículo.
c) Informar en forma ordenada de menor a mayor los montos recaudados por vendedor del artículo número 12. Se deben mostrar los números de vendedores e
importes ordenados por importes del artículo en estudio.
Para el ordenamiento, utilizar una función con parámetros*/

#include <stdio.h>
#include <stdlib.h>

void Carga(float[][20]);
int leyvalida(int, int);
void Mayor(float[][]);
void recaudacion(float[][]);
void Ordenar(float[][]);

int main()
{
    float empresa[15][20];
    Carga(empresa);
    Mayor(empresa);
    recaudacion(empresa);
    return 0;
}

void Carga(float empresa[][20])
{
    int vendedoraux, articuloaux, cantidadv;
    float precio;
    printf("Ingrese numero de vendedor(del 1 al 15- 0 para salir) : ");
    vendedoraux = leyvalida(0, 15);
    while (vendedoraux != 0)
    {
        printf("Ingrese numero de articulo: ");
        articuloaux = leyvalida(1, 20);
        printf("\nIngrese la cantidad vendida: ");
        scanf("%d", &cantidadv);
        printf("\nIngrese el precio: ");
        scanf("%f", &precio);
        empresa[vendedoraux - 1][articuloaux - 1] += (cantidadv * precio);

        printf("Ingrese numero de vendedor(del 1 al 15- 0 para salir) : ");
        vendedoraux = leyvalida(0, 15);
    }
}

int leyvalida(int li, int ls)
{
    int x, band = 0;
    do
    {
        if (band == 1)
        {
            printf("Fuera de rango");
        }
        band = 1;
        scanf("%d", &x);
    } while (x < li || x > ls);
    return x;
}
// a) Informar el número de vendedor / número de artículo que realizó la mayor recaudación (el mayor es único)
void Mayor(float empresa[][20])
{
    int i, j;
    float mayor = 0;
    int maxv, maxart;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (empresa[i][j] > mayor)
            {
                mayor = empresa[i][j];
                maxv = i;
                maxart = j;
            }
        }
    }
    printf("\nEl vendedor que mas articulos vendio fue %d con %d vendidas", maxv + 1, mayor);
    printf("\nEl Articulo que mas vendio fue %d", maxart);
}

// b) Informar el total de recaudación por número de artículo.
void recaudacion(float empresa[][20])
{
    int i, j;
    float recaudacion[20] = {0};
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 20; j++)
        {
            recaudacion[j] += empresa[i][j];
        }
    }

    for (j = 0; j < 20; j++)
    {
        printf("\nEl articulo %d obtuvo una recaudacion de: %.2f", j + 1, recaudacion[j]);
    }
}
// c) Informar en forma ordenada de menor a mayor los montos recaudados por vendedor del artículo número 12. Se deben mostrar los números de vendedores e
// importes ordenados por importes del artículo en estudio.
void Ordenar(float empresa[][20])
{
    int vendedores[15];
    float recaudados[15];
    int i, j, auxv;
    float auxrec;

    for (i = 0; i < 15; i++)
    {
        vendedores[i] = i + 1;
        recaudados[i] = empresa[i][11];
    }
}