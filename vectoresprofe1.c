/*En un negocio trabajan 10 vendedores. Cada vez que se realiza una venta durante el día, se emite una factura donde se indican los siguientes datos:
• Código de vendedor (entero de 1 a 100).
• Importe de la venta (flotante, mayor que cero).

Un vendedor puede realizar más de una venta en el día, una o ninguna.
La carga de datos en un vector finaliza con el ingreso de un código de vendedor igual cero.
Al finalizar la carga, se debe informar:

a. Cantidad de vendedores que no realizaron ventas.
b. El código de vendedor que vendió el menor importe de facturación durante el día sin considerar el cero.
c. Los códigos de los vendedores que realizaron ventas por más de $ 300000.
d. La cantidad de vendedores que no superaron el promedio total de facturación
*/

#include<stdio.h>

int leyvalida (int,int,int);

int main()
{
    int vendedor[10];
    
    do
    {
        for (int i = 0; i < 10; i++)
        {
            vendedor[i]=leyvalida(1,10,0);
        }
            
    } while (vendedor!=0);
    
    return 0;
}

int leyvalida(int li,int ls,int cierre)
{

}