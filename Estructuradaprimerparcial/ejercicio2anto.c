/*/*Realizar un programa en lenguaje C, que permita actualizar los precios de productos en
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
} sEmpresa;

void Carga(sEmpresa[], int);
int leyvalida(int, int);
int Busqueda(sEmpresa[], int, int);

int main()
{
    sEmpresa productos[100];
    int codigoaux, pos, unidadesv;
    float acumuladordia[100] = {0};
    Carga(productos, 100);
    printf("\nIngrese codigo a procesar: ");
    scanf("%d", &codigoaux);
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
                acumuladordia[pos] = (unidadesv * productos[pos].precio);
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
        if (acumuladordia[i] > 0)
        {
            printf("\nEl producto %d vendio %.2f en el dia", productos[i], acumuladordia[i]);
        }
    }

    return 0;
}

void Carga(sEmpresa productos[], int ce)
{
    int i, largo;
    for (i = 0; i < ce; i++)
    {
        printf("\nIngrese codigo de producto: ");
        productos[i].cod = leyvalida(100, 999);
        printf("\nIngrese descripcion del producto: ");
        getchar();
        fgets(productos[i].desc, 31, stdin);
        largo = strlen(productos[i].desc);
        if (productos[i].desc[largo - 1] == '\n')
        {
            productos[i].desc[largo - 1] = '\0';
        }
        printf("\Ingrese precio del producto: ");
        scanf("%f", &productos[i].precio);
        printf("\nIngrese stock del producto: ");
        scanf("%d", &productos[i].stock);
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