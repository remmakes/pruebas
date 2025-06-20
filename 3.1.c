/*3.1 Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
a. Considerar que las palabras están separadas por un único espacio.
b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contarpalabras(char[]);

int main()
{
    char frase[501];
    fgets(frase, 501, stdin);
    puts(frase);
    contarpalabras(frase);
}

void contarpalabras(char ve[])
{
    int i = 0, cont = 0, enPalabra = 0;
    while (ve[i] != '\0' && ve[i] != '\n')
    {
        if (ve[i] != ' ' && enPalabra == 0)
        {
            cont++;
            enPalabra = 1;
        }
        else if (ve[i] == ' ')
        {
            enPalabra = 0;
        }
        i++;
    }
    printf("La cantidad de palabras son %d", cont);
}