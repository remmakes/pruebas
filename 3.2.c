/*3.2 Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las funciones de
la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre coma espacio y
apellido) y mostrarlo*/

#include <stdio.h>
#include <string.h>

int main()
{
    char nombre[40], apellido[20];
    int largo1, largo2;
    puts("Ingrese nombre");
    fgets(nombre, 40, stdin);
    largo1 = strlen(nombre);
    if (nombre[largo1 - 1] == '\n')
    {
        nombre[largo1 - 1] = '\0';
    }
    puts("Ingrese apellido");
    fgets(apellido, 20, stdin);
    largo2 = strlen(apellido);
    if (nombre[largo2 - 1] == '\n')
    {
        nombre[largo2 - 1] = '\0';
    }
    strcat(nombre, ", ");
    strcat(nombre, apellido);
    puts(nombre);
    return 0;
}