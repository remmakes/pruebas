/*7.9 En un negocio trabajan 12 vendedores. Cada vez que se realiza una venta durante el día, se emite una factura
donde se indican los siguientes datos:
• Número de Factura (entero, mayor que cero).
• Código de vendedor (entero de 1 a 12).
• Importe de la venta (real, mayor que cero).
La información termina con un número de Factura igual a cero. Al principio del ingreso, se debe solicitar la
fecha del día de procesamiento. Se pide informar con las leyendas aclaratorias:
• Importe total de facturación por cada vendedor y Cantidad de facturas emitidas por vendedor, ,
con el siguiente formato:
                      Venta del Día: XX/XX/XXXX
Nro. de
Vendedor       Importe vendido      Cantidad de facturas emitidas
xx                 XXXXX,XX              xx     
xx                 XXXXX,XX              xx
…                  …………                  …
xx                 XXXXX, XX            xx
                    …………                TOTAL XXXXXXX,XX xxx
                   XXXXX, XX*/

#include<stdio.h>

int leyvalida(int,int,int);
int leyvalida2(int);
int main()
{
    int vendedor[12],factura;
    for (int i = 0; i < 12; i++)
    {
        vendedor[i]=leyvalida(1,12,0);
    }
    do
    {
        /* code */
    } while (factura!=0);
    
    

    factura=leyvalida2(0);
    
    return 0;
}

int leyvalida(int li,int ls,int cierre)
{
    int x,band=0;
    do
    {
        if (band==1)
        {
            printf("Fuera de rango");
        }
        band=1;
        scanf("%d",&x);
        
    } while ((x<li || x>ls) && x!=cierre);
    return x;
}

int leyvalida2 (int close)
{
    int y,band=0;
    do
    {
        if (band==1)
        {
            printf("Fuera de rango");
        }
        band=1;
        scanf("%d",&y);
        
    } while (y>close);
    return y;
}

