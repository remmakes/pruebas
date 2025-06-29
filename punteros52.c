/*5.2 Definir dos números enteros y dos punteros a dichos números. Accediendo mediante los punteros sumar
ambos números y mostrar el resultado por pantalla*/

#include<stdio.h>

int main()
{
    int num1=10, num2=5;
    int *p1,*p2;
    p1= &num1;
    p2= &num2;
    printf("La suma es %d",*p1+*p2);

    return 0;
}