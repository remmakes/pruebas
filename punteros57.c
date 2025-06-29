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

void Carga(sProductos *);

int main()
{
    sProductos pruebita[2];
    sProductos *pP1;
    pP1=pruebita;
    Carga(pP1);
    for (int i = 0; i < 2; i++)
    {
        printf("\nEl codigo es: %d, la descripcion es %s,el precio es %.2f",(pP1+i)->codigo,(pP1+i)->descripcion,(pP1+i)->precio);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("\nEl codigo es: %d, la descripcion es %s,el precio es %.2f",(*(pP1+i)).codigo,(*(pP1+i)).descripcion,(*(pP1+i)).precio);
    }
    
    
    return 0;
}

void Carga (sProductos *p)
{
    int largo;
    for (int i = 0; i < 2; i++)
    {
        printf("Ingrese codigo: ");
        scanf("%d",&p->codigo);
        getchar();
        printf("\nIngrese descripcion:");
        fgets(p->descripcion,31,stdin);       
        largo=strlen(p->descripcion);
        if (p->descripcion[largo-1]=='\n')
        {
            p->descripcion[largo-1]='\0';
        }
        printf("\nIngrese precio: ");
        scanf("%f",&p->precio);
        p++;
    }   
}
