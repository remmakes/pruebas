/*5.2 Definir dos números enteros y dos punteros a dichos números. Accediendo mediante los punteros sumar
ambos números y mostrar el resultado por pantalla.*/

#include <stdio.h>

int main()
{
    int *p1, *p2, n1=2,n2=3;
    p1=&n1;
    p2=&n2;
    printf("%d",*p1+*p2);
    return 0;
}