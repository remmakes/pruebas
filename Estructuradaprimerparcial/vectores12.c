/*1.2 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.*/

#include <stdio.h>
#include <stdlib.h>

void IngresaCodigos(int []);
int leyvalida(int,int,int);
int Busqueda(int [],int);
void Mayor(int [],int []);
void Menor(int [],int []);

int main()
{
    int productos[10],ventas[10]={0},cantidad,numprod;
    int encontrado=0;
    IngresaCodigos(productos);
    printf("\nIngrese codigo de producto (0 para salir): ");
    scanf("%d",&numprod);
    while (numprod!=0)
    {
        encontrado=Busqueda(productos,numprod);
        if (encontrado!=0)
        {
            printf("\nIngrese la cantidad solicitada: ");
            scanf("%d",&cantidad);
            ventas[encontrado]+=cantidad;
        }else if(encontrado==0)
            printf("Producto no encontrado");

        printf("\nIngrese codigo de producto (0 para salir): ");
        scanf("%d",&numprod);
        
    }
    //a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
    for (int i = 0; i < 10; i++)
    {
        printf("\nDel producto %d,se solicitaron %d unidades",productos[i],ventas[i]);
    }
    Mayor(productos,ventas);
    Menor(productos,ventas);

    return 0;
}

void IngresaCodigos(int productos[])
{
    int i,j,repetido=0;
    for ( i = 0; i < 10; i++)
    {
        do
        {
        printf("Ingrese codigo de producto: ");
        productos[i]=leyvalida(1000,9999,0);
        for (j = 0; j < i; j++)
        {
            if (productos[i]==productos[j])
            {
                repetido=1;
            }
            
        }
            
        } while (repetido!=0);
        
        
    }
    
}

int leyvalida(int li,int ls,int cierre)
{
    int x,band=0;
    do
    {
        if(band==1)
        {
            printf("\nCodigo erroneo");
        }
        band=1;
        scanf("%d",&x);
    } while ((x<li || x>ls)&& x!=0);
    return x;
}

int Busqueda(int vector[],int nb)
{
    int i,encuentra=0;
    for ( i = 0; i < 10; i++)
    {
        if (vector[i]==nb)
        {
            encuentra=i;
        }
        
    }
    return encuentra;

}

void Mayor(int productos[],int ventas[])
{
    int i,mayor=ventas[0],identi;
    for ( i = 1; i < 10; i++)
    {
        if (ventas[i]>mayor)
        {
            mayor=ventas[i];
            identi=i;
        }
        
    }
    printf("El producto que mayor ventas tuvo es %d,con %d unidades vendidas",productos[identi] ,mayor);
    
}