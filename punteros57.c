/*5.7 Dada la siguiente estructura:
typedef struct
{
int codigo;
char descripcion[31];
float precio;
}sProductos
a. Crear una variable del tipo sProductos
b. Ingresar por teclado los campos
c. Crear un puntero a dicha estructura
d. Mostrar los datos ingresados mediante el puntero utilizando las dos nomenclaturas posibles*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    int codigo;
    char descripcion[31];
    float precio;
}sProductos;

void Carga(sProductos []);

int main()
{
    sProductos pruebita[2];
    sProductos *pP1, *pP2;
    Carga(pruebita);
    pP1=&pruebita[0];
    pP2=&pruebita[1];
    printf("\nMostrando con pP1");
    printf("\nEl codigo del producto es:%d",pP1->codigo);
    printf("\nLa descripcion del producto es: %s",pP1->descripcion);
    printf("\nEl precio es: %.2f",pP1->precio);

    printf("\nMostrando con pP2");
    printf("\nEl codigo del producto es:%d",(*pP2).codigo);
    printf("\nLa descripcion del producto es: %s",(*pP2).descripcion);
    printf("\nEl precio es: %.2f",(*pP2).precio);

    return 0;
}

void Carga (sProductos ve[])
{
    int largo;
    for (int i = 0; i < 2; i++)
    {
        printf("Ingrese codigo: ");
        scanf("%d",&ve[i].codigo);
        getchar();
        printf("\nIngrese descripcion:");
        fgets(ve[i].descripcion,31,stdin);       
        largo=strlen(ve[i].descripcion);
        if (ve[i].descripcion[largo-1]=='\n')
        {
            ve[i].descripcion[largo-1]='\0';
        }
        printf("\nIngrese precio: ");
        scanf("%f",&ve[i].precio);
    }
    
}
