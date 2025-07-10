/*1.5 Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe
ordenar de forma ascendente la colección con dichos códigos para permitir realizar búsquedas binarias.
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código
de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una
venta de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/

#include <stdio.h>
#include <stdlib.h>

void Ordenamiento ( int [],int);
void Carga(int []);
int leyvalida(int ,int);
int Busqueda(int [],int,int);

int main ()
{
    int productos[15],vendedores[5]={1001,1002,1003,1004,1005};
    int i,numeroaux,pos,cantidad,vendedoraux;
    for ( i = 0; i < 15; i++)
    {
        do
        {
            printf("Ingrese codigo de producto (del 100 al 999): ");
            numeroaux=leyvalida(100,999);
            pos=Busqueda(productos,numeroaux,i);
            if (pos!=-1)
            {
                printf("\nCodigo duplicado");
            }
            
        } while (pos!=-1);
        productos[i]=numeroaux;
    }

    Ordenamiento(productos,15);
    printf("\nIngrese numero de vendedor: ");
    scanf("%d",&vendedoraux);
    while (vendedoraux!=0)
    {
        /* code */
    }
    
    return 0;
}

int Busqueda(int productos[],int numb,int ce)
{
    int i=0,pos=-1;
    while (pos==-1 && i<ce)
    {
        if (productos[i]==numb)
        {
            pos=i;
        }
        i++;
    }
    return pos;
}

int leyvalida(int li,int ls)
{
    int x,band=0;
    do
    {
        if (band==1)
        {
            printf("\nfuera de rango");
        }
        band=1;
        scanf("%d",&x);
    } while (x<li || x>ls);
    return x;
}

void Ordenamiento(int vector[],int ce)
{
    int i,j,aux;
    for ( i = 0; i < ce; i++)
    {
        for ( j = 0; j > ce-1-i; j++)
        {
            if (vector[j]<vector[j+1])
            {
                aux=vector[j];
                vector[j]=vector[j+1];
                vector[j+1]=aux;
            }
            
        }
        
    }
    
}