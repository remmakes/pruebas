/*Se desea estudiar los importes de las ventas realizadas durante el día por una empresa donde trabajan 15 vendedores y se comercializan 
20 artículos. Para tal fin, al finalizar el horario laboral, se nos suministran diversas planillas donde figura por cada venta de un 
determinado artículo: el número de vendedor que realizó la venta, el número de artículo, la cantidad vendida y el precio unitario 
de dicho artículo.
. Número de vendedor (de 1 a 15) validar el ingreso con una función
. Número de artículo (de 1 a 20) validar el ingreso con la misma función
. Cantidad vendida (int)
. Precio Unitario (float)
Dichos datos, se ingresarán por teclado en forma desordenada, hasta la lectura de un número de vendedor 0 (cero). Se puede repetir durante el día, 
la venta de un artículo para un mismo vendedor, y no hay necesariamente venta de todos los artículos.
Desarrollar la codificación en lenguaje C que permita:
a) Informar el número de vendedor / número de artículo que realizó la mayor
recaudación (el mayor es único)
b) Informar el total de recaudación por número de artículo.
c) Informar en forma ordenada de menor a mayor los montos recaudados por vendedor del artículo número 12. Se deben mostrar los números de 
vendedores e importes ordenados por importes del artículo en estudio. Para el ordenamiento, utilizar una función con parámetros.*/

#include <stdio.h>
#include <stdlib.h>

int leyvalida(int,int);
void mayorvendedor(float [][]);
void totalrecaudacion(float [][],float []);
void orden(float [][],float []);

int main ()
{
    float empresa[15][20]={{0}};
    float recaudacion[20]={0};
    int vendedoraux,articuloaux;
    int cantv;
    float precio;
    printf("Ingrese numero de vendedor: ");
    vendedoraux=leyvalida(0,15);
    while (vendedoraux!=0)
    {
        printf("\nIngrese numero de articulo (del 1 al 20): ");
        articuloaux=leyvalida(1,20);
        printf("\nIngrese la cantidad vendida: ");
        scanf("%d",&cantv);
        printf("\nIngrese el precio: ");
        scanf("%f",&precio);
        empresa[vendedoraux-1][articuloaux-1]+=(cantv*precio);

        printf("Ingrese numero de vendedor: ");
        vendedoraux=leyvalida(0,15);        
    }
    
    mayorvendedor(empresa);
    totalrecaudacion(empresa,recaudacion);
    orden(empresa,recaudacion);
    return 0;
}

int leyvalida (int li,int ls)
{
    int x,band=0;
    do
    {
        if (band==1)
        {
            printf("\nFUERA DE RANGO: ");
        }
        band=1;
        scanf("%d",&x);
    } while (x<li || x>ls);
    return x;
}

void mayorvendedor(float empresa[][20])
{
    float mayor=empresa[0][0];
    int i,j,maxv,maxart;
    for ( i = 0; i < 15; i++)
    {
        for ( j = 0; j < 20; j++)
        {
            if (empresa[i][j]>mayor)
            {
                mayor=empresa[i][j];
                maxv=i;
                maxart=j;
            }    
        }
    }
    printf("\nEl vendedor que mas vendio fue %d, con el articulo %d y con la cantidad total de: %.2f",maxv+1,maxart+1,mayor);
}

void totalrecaudacion(float empresa[][20],float recaudacion[])
{
    int i,j;
    for ( i = 0; i < 20; i++)
    {
        for(j=0;j<15;j++)
        {
            recaudacion[i]+=empresa[j][i];
        }
    }
    
    for ( i = 0; i < 20; i++)
    {
            printf("\nEl total de recaudacion del articulo %d fue de %.2f",i+1,recaudacion[i]); 
    }
    
}

/*c) Informar en forma ordenada de menor a mayor los montos recaudados por vendedor del artículo número 12. Se deben mostrar los números de 
vendedores e importes ordenados por importes del artículo en estudio. Para el ordenamiento, utilizar una función con parámetros.*/
void orden(float empresa[][20],float recaudacion[])
{
    int i,j,aux;
    //float menor=empresa[0][12];
    for ( i = 0; i < 15; i++)
    {
        for (j=0;j<15-1-i;j++)
        if (empresa[j][12]<empresa[j+1][12])
        {
            aux=empresa[j][12];
            empresa[j][12]=empresa[j+1][12];
            empresa[j+1][12]=aux;
        }    
    }
    for ( i = 0; i < 15; i++)
    {
        printf("El vendedor %d,vendio %.2f",);
    }
    
}