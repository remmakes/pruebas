#include <stdio.h>

int main()
{
    int num = 10, *puntero;
    printf("Contenido de num: %d\n", num);
    printf("\nUbcacion de num: %p", &num);
    puntero = &num;
    printf("\nContenido de puntero: %p", puntero);
    printf("\nContenido de num a traves del puntero: %d", *puntero);
    return 0;
}