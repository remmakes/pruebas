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

void IngresaCodigos(int[], int);
int BuscarDuplicado(int[], int, int);

int main()
{
    int Productos[10];
    IngresaCodigos(Productos, 10);
}

void IngresaCodigos(int ve[], int ce)
{
    int i, codigo,pos;
    for (i = 0; i < ce; i++)
    {
        do
        {
            printf("Ingrese un codigo de 4 cifras: ");
            scanf("%d", &codigo);
            if (codigo >999 && codigo<10000)
            {
                pos = BuscarDuplicado(ve, codigo, i);
            if (pos==-1)
            {
                printf("Numero duplicado intente otro");
            }
            }
        } while (pos!=-1);
        
    }
}

int BuscarDuplicado (int ve[],int valorbuscado,int limit)
{
    
}