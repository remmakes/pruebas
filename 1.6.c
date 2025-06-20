/*1.6 Dado un conjunto de 10 números enteros ordenados de menor a mayor, ingresar por teclado 3 números más
no ordenados. Insertarlos donde correspondan. Mostrar en pantalla la serie inicial y la final.*/

#include <stdio.h>

void Ingresodatos(int[], int);
void Ordenardatos(int[], int);
int main()
{
    int numeros[13], add;
    Ingresodatos(numeros, 10);
    Ordenardatos(numeros, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", numeros[i]);
    }
    for (int i = 10; i < 13; i++)
    {
        printf("Ingrese 3 numeros adicionales: ");
        scanf("%d", &add);
        numeros[i] = add;
    }
    Ordenardatos(numeros, 13);

    for (int i = 0; i < 13; i++)
    {
        printf("%d \n", numeros[i]);
    }

    return 0;
}

void Ingresodatos(int vnumero[], int ce)
{
    int i, numero;
    for (i = 0; i < ce; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        vnumero[i] = numero;
    }
}

void Ordenardatos(int ve[], int ce)
{
    int i, posmin, aux, j;
    for (i = 0; i < ce - 1; i++)
    {
        posmin = i;
        for (j = i + 1; j < ce; j++)
        {
            if (ve[j] < ve[posmin])
            {
                posmin = j;
            }
        }
        if (posmin != i)
        {
            aux = ve[i];
            ve[i] = ve[posmin];
            ve[posmin] = aux;
        }
    }
}