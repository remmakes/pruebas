/*6.7 Se dispone de un archivo llamado Stock.dat que contiene la información de los productos que vende una
fábrica. En el archivo se guarda:
• Código de artículo (entero)
• Descripción (50 caracteres máximo)
• Stock (entero)
Luego se ingresan por teclado las ventas a realizar indicando:
• Código de artículo
• Cantidad
La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
• Código de artículo
• Cantidad faltante
Si ya hay un registro previo en dicho archivo de faltantes con el mismo producto debe incrementarse la
cantidad.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int cod;
    char descripcion[51];
    int stock;
}sStock;

typedef struct 
{
    int codigo;
    int faltante;
}sFaltante;

void ventas (FILE *,int);

int main ()
{
    sStock carga;
    FILE* archivo;
    int articulo;
    archivo=fopen("Stock.dat","r+b");
    if (archivo==NULL)
    {
        printf("No existe archivo");
        exit(1);
    }
    printf("Ingrese articulo deseado: ");
    scanf("%d",&articulo);
    while (articulo!=0)
    {
        ventas(archivo,articulo);

        printf("Ingrese articulo deseado: ");
        scanf("%d",&articulo);
    }
    
    
    return 0;
}

void ventas(FILE* archivo,int articulo)
{
    sStock reg;
    sFaltante nohay;
    int num,faltante,encontrado;
    FILE* falta;
    falta=fopen("Faltantes.dat","ab");
    if (falta==NULL)
    {
        printf("error al crear el archivo");
        exit(1);
    }
    
    fread(&reg,sizeof(sStock),1,archivo);
    while (!feof(archivo))
    {
        
        if (reg.cod==articulo)
        {
            encontrado=1;
            printf("Ingrese cantidad deseada: ");
            scanf("%d",&num);
            if (reg.stock>=num)
            {
                reg.stock-=num;
                fseek(archivo,sizeof(sStock)*-1,SEEK_CUR);
                fwrite(&reg,sizeof(sStock),1,archivo);
            }
            else if (reg.stock<num)   
            {
                faltante=num-reg.stock;
                reg.stock=reg.stock-(num-faltante);
                fwrite(&nohay,sizeof(sFaltante),1,falta);
            }
            
            
        }
        if (encontrado==0)
        {
            printf("Codigo incorrecto");
        }
        fread(&reg,sizeof(sStock),1,archivo);
    }
    rewind(archivo);
    fclose(falta);
}