/*5.4 Hacer un programa que cargue un vector de 10 enteros y lo muestre usando una función para cargar y otra
mostrar sin utilizar subíndices.*/

#include<stdio.h>

void Carga(int []);
void Mostrar (int[]);

int main ()
{
    int num[10];
    Carga (num);
    Mostrar(num);
    return 0;
}

void Carga(int ve[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese un numero: ");
        scanf(" %d",(ve+i));
    }    
}

void Mostrar (int *ve)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",*(ve+i));
    }
}