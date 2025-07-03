/* Se dispone de un archivo binario con precios de productos que se comercializan en los estados partes del Mercosur con el siguiente diseño de registro:
• Código de Producto (entero)
• Descripción ( 30 caracteres máximo)
• País destino (char ‘P’: Paraguay, “V’: Venezuela ‘A’: Argentina, ‘B’: Brasil, ‘U’: Uruguay)
• Precio Unitario (float)
Se ha determinado que a los productos que se comercialicen en Argentina (letra A), se les realice un incremento del 10 %. Realizar un programa en “C”
que permita actualizar directamente sobre el archivo los precios de los productos indicados.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int codigo;
    char descripcion[31];
    char PaisD;
    float precio;
}sRegistro;

int main ()
{
    sRegistro product;
    FILE* archivo;
    archivo=fopen("mercosur.dat","r+b");
    if (archivo==NULL)
    {
        printf("No existe el archivo");
        exit(1);
    }

    fread(&product,sizeof(sRegistro),1,archivo);
    while (!feof(archivo))
    {
        if (product.PaisD=='A')
        {
            product.precio*=1.10;
            fseek(archivo,sizeof(sRegistro)*-1,SEEK_CUR);
            fwrite(&product,sizeof(sRegistro),1,archivo);
            fflush(archivo);
        }
        fread(&product,sizeof(sRegistro),1,archivo);
    }
    fclose(archivo);
    
    return 0;
}