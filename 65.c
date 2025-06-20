/*6.5. Confeccionar un programa que permita ingresar varias ternas de valores a punto flotante, que finalice al
ingresar una terna con los valores ORDENADOS en forma creciente. Para cada terna exhibir la siguiente
pantalla:
** OPCIONES POSIBLES **
1 – Mayor valor
2 – Promedio
3 – Suma
4 - Finalizar
** Digite su opción:
Según la opción deseada debe aparecer en pantalla el resultado, sin borrar el menú. No admitir otros
valores de opción. Confeccionar y utilizar una función PARA CADA UNA de las opciones y otra para detectar
la condición final.*/

#include <stdio.h>

float MayorValor(float, float, float);
float promedio(float, float, float);
float Suma(float, float, float);
int opcion();

int main()
{
    int Opcion;
    float n1, n2, n3, mayor;
    printf("** OPCIONES POSIBLES **\n1 - Mayor valor\n2 - Promedio\n3 - Suma\n4 - Finalizar");

    printf("\nIngrese 3 valores: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    do
    {

        Opcion = opcion();
        switch (Opcion)
        {
        case 1:
            mayor = MayorValor(n1, n2, n3);
            printf("El mayor es : %.2f", mayor);
            break;
        case 2:
            printf("\nEl promedio es %.2f", promedio(n1, n2, n3));
            break;
        case 3:
            printf("\nLa suma es %.2f", Suma(n1, n2, n3));
            break;
        default:
            break;
        }
        // Opcion=opcion();
    } while (Opcion != 4);

    return 0;
}

float MayorValor(float n1, float n2, float n3)
{
    if (n1 > n2 && n1 > n3)
    {
        return n1;
    }
    if (n2 > n3 && n2 > n1)
    {
        return n2;
    }
    else
        return n3;
}

float promedio(float n1, float n2, float n3)
{
    return (n1 + n2 + n3) / 3;
}

float Suma(float n1, float n2, float n3)
{
    return n1 + n2 + n3;
}

int opcion()
{
    int x, band = 0;
    do
    {
        printf("\nIngrese una opcion: ");
        scanf("%d", &x);
    } while (x < 1 || x > 4);

    return x;
}