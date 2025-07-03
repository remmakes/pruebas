/*6.6 Dado el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Realizar un programa que permita eliminar productos dado su código*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int codigo;
    float precio;
    char descripcion [51];
}sRegistro;

void Eliminar(int,FILE *,FILE *);

int main ()
{
    sRegistro prod;
    FILE * archorg, *archivotemp;
    int codelim;
    printf("Ingrese codigo que desea eliminar: ");
    scanf("%d",&codelim);
    Eliminar(codelim,archorg,archivotemp);
    return 0;
}

void Eliminar(int codelim,FILE * archorg,FILE *archivotemp)
{
    sRegistro prod;
    archorg=fopen("registro.dat","rb");
    archivotemp=fopen("rtemp.tmp","wb");
    if (archorg==NULL)
    {
        printf("No se encontro el archivo");
        getchar();
        exit (1);
    }
    fread(&prod,sizeof(sRegistro),1,archorg);
    while (!feof(archorg))
    {
        if (prod.codigo!=codelim)
        {
            fwrite(&prod,sizeof(sRegistro),1,archivotemp);
        }
        fread(&prod,sizeof(sRegistro),1,archorg);
    }
    
    fclose(archorg);
    fclose(archivotemp);
    remove("registro.dat");
    rename("rtemp.tmp","registro.dat");

}