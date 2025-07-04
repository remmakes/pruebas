/*6.5 Se desea realizar un programa que permita actualizar la lista de precios de una empresa en forma individual
a cada uno de sus productos.
Los productos que están guardados en el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación
de precios finaliza con un código de producto igual a 0.
Al finalizar exportar a un archivo con formato de texto (.csv) para que la lista de precios pueda ser
visualizada directamente utilizando un programa de planillas de cálculo como por ejemplo el Excel.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int codigo;
    float precio;
    char descripcion[51];
}sProductos;

void IngresoDatos(char *);

int main ()
{
    sProductos prod;
    FILE *arch;
    int codprod,encontrado;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
    {
        printf("No existe, creando...");
        IngresoDatos("productos.dat");
        exit(1);
    }
    printf("Ingrese codigo de producto: ");
    scanf("%d",&codprod);
    while (codprod!=0)
    {
        encontrado=0;
        rewind(arch);
        fread(&prod,sizeof(sProductos),1,arch);
        while (!feof(arch))
        {
            if (codprod==prod.codigo)
        {
            encontrado=1;
            printf("Ingrese nuevo precio: ");
            scanf("%f",&prod.precio);
            fseek(arch,sizeof(sProductos)*-1,SEEK_CUR);
            fwrite(&prod,sizeof(sProductos),1,arch);
        }
        fread(&prod,sizeof(sProductos),1,arch);
        
        }
        if (encontrado==0)
        {
            printf("Producto no encontrado");
        }
        
        printf("Ingrese codigo de producto: ");
        scanf("%d",&codprod);
    }
    fclose(arch);
    return 0;
}

void IngresoDatos(char * archivo)
{
    sProductos pr;
    FILE *archivo;
    archivo=fopen("productos.dat","wb");
    if (archivo==NULL)
    {
        printf("No se pudo crear");
        exit(1);
    }

    printf("\nIngrese codigo de producto: ");
    scanf("%d",&pr.codigo);
    while (pr.codigo!=0)
    {
        printf("Ingrese precio: ");
        scanf("%f",&pr.precio);
        getchar();
        printf("Ingrese descripcion: ");
        gets(pr.descripcion);
        fwrite(&pr,sizeof(sProductos),1,archivo);

        printf("\nIngrese codigo de producto: ");
        scanf("%d",&pr.codigo);
    }
    
}