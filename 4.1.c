/*4.1 Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION CANTIDAD UNIDADES
VENDIDAS
IMPORTE TOTAL
VENDIDO
XXXXXXX XXXX $XXXXX,XX*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
struct Productos
{
    char codigo[6];
    float precio;
    char descripcion[31];
    int cantvendidas;
    float imptotalvend;
};

void Ingreso(struct Productos[], int);
void Mostrarventas(struct Productos[], int, int);

int main()
{
    int x, cant[TAM] = {0}, cantidad;
    char compra[6];
    struct Productos prod[TAM];
    Ingreso(prod, TAM);
    do
    {
        printf("Ingrese la cantidad solicitada: ");
        scanf("%d", &cantidad);
        getchar();
        if (cantidad != 0)
        {
            printf("Ingrese el codigo del producto a comprar: ");
            fgets(compra, 6, stdin);
            x = strlen(compra);
            if (compra[x - 1] == '\n')
                compra[x - 1] = '\0';
            getchar();
            for (int i = 0; i < TAM; i++)
            {
                if (strcmpi(prod[i].codigo, compra) == 0)
                {
                    cant[i] += cantidad;
                }
            }
        }
    } while (cantidad != 0);

    Mostrarventas(prod, cant, TAM);
    return 0;
}

void Ingreso(struct Productos prod[TAM], int ce)
{
    int i = 0, largo;
    printf("\nIngrese la descripcion: ");
    fgets(prod[i].descripcion, 31, stdin);
    largo = strlen(prod[i].descripcion);
    if (prod[i].descripcion[largo - 1] == '\n')
        prod[i].descripcion[largo - 1] = '\0';
    while (strcmpi(prod[i].descripcion, "fin") != 0 && i < ce)
    {
        printf("Ingrese el precio: ");
        scanf("%f", &prod[i].precio);
        getchar();
        printf("Ingrese el codigo del producto: ");
        fgets(prod[i].codigo, 6, stdin);
        largo = strlen(prod[i].codigo);
        if (prod[i].codigo[largo - 1] == '\n')
            prod[i].codigo[largo - 1] = '\0';
        printf("\nIngrese la cantidad vendida el mes pasado: ");
        scanf("%d", &prod[i].cantvendidas);
        prod[i].imptotalvend = prod[i].cantvendidas * prod[i].precio;
        i++;

        if (i < ce)
        {
            printf("\nIngrese la descripcion: ");
            fgets(prod[i].descripcion, 31, stdin);
            largo = strlen(prod[i].descripcion);
            if (prod[i].descripcion[largo - 1] == '\n')
                prod[i].descripcion[largo - 1] = '\0';
        }
    }
}

void MostrarVentas(struct Productos prod[], int ventas[], int ce)
{
    int i;
    printf("%-30s %15s %20s", "DESCRIPCION", "CANT TOTAL VENDIDA", "IMPORTE TOTAL");
    for (i = 0; i < ce; i++)
    {
        prod[i].cantvendidas += ventas[i];
        prod[i].imptotalvend += (prod[i].precio * ventas[i]);
        printf("\n%-30s %15d %15s%.2f", prod[i].descripcion, prod[i].cantvendidas, "$", prod[i].imptotalvend);
    }
}