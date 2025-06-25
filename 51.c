/*5.1 Crear una variable entera y un puntero a dicha variable
Asignar el valor 10 a la variable mediante el puntero
Mostrar:
a) la dirección de la variable
b) la dirección del puntero
c) el contenido de la variable
d) el contenido de la variable accediendo mediante el puntero
e) el contenido del puntero*/

#include <stdio.h>

int main()
{
    int variable;
    int *p;
    p = &variable;
    *p = 10;
    printf("a) Direccion de la variable: %p\n", &variable);
    printf("b) Direccion del puntero: %p\n", &p);
    printf("c) Contenido de la variable: %d\n", variable);
    printf("d) Contenido de la variable a traves del puntero %d\n", *p);
    printf("e) Contenido del puntero %p: ", p);
    return 0;
}