/*3.4 Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad exacta
de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y la carga de
los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del día y por cada
venta se ingresa el código de producto y cantidad de unidades vendidas terminando con una cantidad igual
a 0. Se solicita:
a. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
b. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.*/

#include <stdio.h>
#include <string.h>

void CargaDatos(char[][5], float[],int);
int leyvalida(int, int);
void Ventas(char[][], float[], int[],int);

int main()
{
    int tam;
    char codigo[50][5];
    float precio[50];
    int cantvend[50];
    printf("Ingrese la cantidad de productos (menor a 50): ");
    tam = leyvalida(1, 50);
    CargaDatos(codigo, precio,tam);
    Ventas(codigo, precio, cantvend,tam);
    return 0;
}

int leyvalida(int li, int ls)
{
    int x, band = 0;
    do
    {
        if (band == 1)
            puts("Fuera de rango");
        band = 1;
        scanf("%d", &x);
    } while (x < li || x > ls);
    return x;
}

void CargaDatos(char codigos[][5], float precio[],int ce)
{
    int i = 0,largo;
    char palabra[] = "fin";
    puts("Ingrese un codigo de 3 caracteres");
    fgets(codigos[i], 5, stdin);
    largo = strlen(codigos[i]);
    if (codigos[i][largo-1]=='\n')
    {
        codigos[i][largo - 1] = '\0';
    }
    
    while (strcmpi(codigos[i],palabra)!=0 && i<ce)
    {
        printf("Ingrese el precio: ");
        scanf("%f", &precio[i]);
        i++;
        if (i<ce)
        {
            puts("Ingrese un codigo de 3 caracteres");
            fgets(codigos[i], 5, stdin);
            largo = strlen(codigos[i]);
            if (codigos[i][largo-1]=='\n')
        {
            codigos[i][largo - 1] = '\0';
        }
        }
        
    }
}

void Ventas(char codigo[][5],float precios[],int cantvend[],int ce)
{
    int i=0,Ventas;
    char palabra[5];
    do
    {   puts("Primero ingrese codigo de producto: ");
        fgets(palabra, 5, stdin);
        int largo = strlen(palabra);
        if (palabra[largo - 1] == '\n')
            palabra[largo - 1] = '\0';
        int encontrado = 0;
        for (i = 0; i < ce; i++)
        {
            if (strcmpi(palabra,codigo[i]==0))
            {
                encontrado = 1;
                printf("Ingrese cantidad vendida: ");
                scanf("%d", &Ventas);
                getchar();
                cantvend[i] += Ventas;
            }
            
        }

    } while (Ventas!=0);
    
    

}