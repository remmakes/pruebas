/*Realizar un programa en lenguaje C, que permita actualizar los precios de productos en
forma individual. La empresa trabaja con 100 productos con la siguiente estructura:
. Código (entero) (100-999)
. Desc (30)
. precio (float)
. stock (entero)
Primero, se ingresarán los datos en un vector de estructuras. Una vez finalizada la carga, se solicitarán códigos de productos de los cuales se quiere
procesar la cantidad de unidades vendidas por codigo con el siguiente formato
. Código (entero) (100-999)
. unidades vendidas (entero).
En caso de existir el código en el vector, se procesara la venta de los productos. Actualizando el stock solo si la cantidad solicitada es suficiente.
Se finalizara la venta con un codigo de producto igual a cero.Donde debe informarse el codigo producto y lo recaudado en el dia.
Para la búsqueda del código en el vector de estructuras, utilizar una función.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    char desc[31];
    float precio;
    int stock;
    float recaudado;
} sEmpresa;

void Carga(sEmpresa[], int);
int leyvalida(int, int,int);
int Busqueda(sEmpresa[], int, int);

int main()
{
    sEmpresa productos[100];
    int codigoaux, pos, unidadesv;
    Carga(productos, 100);
    printf("\nIngrese codigo a procesar: ");
    codigoaux=leyvalida(100,999,0);
    while (codigoaux != 0)
    {
        pos = Busqueda(productos, codigoaux, 100);
        if (pos != -1)
        {
            printf("\nIngrese unidades vendidas: ");
            scanf("%d", &unidadesv);
            if (productos[pos].stock >= unidadesv)
            {
                productos[pos].stock -= unidadesv;
                productos[pos].recaudado += (unidadesv * productos[pos].precio);
            }
            else
                printf("\nCantidad insuficiente en stock");
        }
        else if (pos == -1)
        {
            printf("\nProducto no encontrado");
        }
        printf("\nIngrese codigo a procesar: ");
        scanf("%d", &codigoaux);
    }

    for (int i = 0; i < 100; i++)
    {
        if (productos[i].recaudado > 0)
        {
            printf("\n%s con codigo %d vendio %.2f en el dia",productos[i].desc, productos[i].cod, productos[i].recaudado);
        }
    }

    return 0;
}

void Carga(sEmpresa productos[], int ce)
{
    int i, largo,precioaux,pos;
    for (i = 0; i < ce; i++)
    {
        do
        {
            printf("\nIngrese codigo de producto: ");
            productos[i].cod = leyvalida(100, 999,999);
            pos=Busqueda(productos,productos[i].cod,i);
            if (pos>=0)
            {
                printf("\nCodigo repetido, ingrese otro");
            }
            
        } while (pos!=-1);
        
      
        printf("\nIngrese descripcion del producto: ");
        getchar();
        fgets(productos[i].desc, 31, stdin);
        largo = strlen(productos[i].desc);
        if (productos[i].desc[largo - 1] == '\n')
        {
            productos[i].desc[largo - 1] = '\0';
        }
        do
        {
            printf("\Ingrese precio del producto: ");
            scanf("%f", &productos[i].precio);
        } while (productos[i].precio<=0);
        do
        {
            printf("\nIngrese stock del producto: ");
            scanf("%d", &productos[i].stock);
        } while (productos[i].stock<=0);
        

    }
}

int leyvalida(int li, int ls,int cierre)
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

    } while ((x < li || x > ls )&& x!=cierre);
    return x;
}

int Busqueda(sEmpresa productos[], int codb, int ce)
{
    int i = 0, pos = -1;
    while (pos == -1 && i < ce)
    {
        if (productos[i].cod == codb)
        {
            pos = i;
        }
        else
            i++;
    }
    return pos;
}