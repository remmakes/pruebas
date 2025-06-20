/*1.1 Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra*/

#include <stdio.h>
#include <time.h>

void CargaAleatoria(int[], int);
int Minimo(int[], int);
int BuscarMax(int[], int);
void MostrarMinimo(int[], int, int);
void MostrarMaximo(int[], int, int);
int main()
{

    srand(time(NULL));
    int Vector[20] = {0};
    int i, min, max;
    CargaAleatoria(Vector, 20);
    for (i = 0; i < 20; i++)
    { // PRUEBA DE QUE EL VECTOR SE CARGA BIEN
        printf("%d\n", Vector[i]);
    }

    min = Minimo(Vector, 20);
    MostrarMinimo(Vector, min, 20);
    max = BuscarMax(Vector, 20);
    MostrarMaximo(Vector, max, 20);
    return 0;
}

void CargaAleatoria(int ve[], int cant)
{
    int num, i;
    for (i = 0; i < cant; i++)
    {
        num = rand() % 900 + 100;
        ve[i] = num;
    }
}

int Minimo(int ve[], int cant)
{
    int i, mini;
    mini = ve[0];
    for (i = 1; i < cant; i++)
    {
        if (ve[i] < mini)
            mini = ve[i];
    }
    return mini;
}

void MostrarMinimo(int ve[], int min, int ce)
{
    int i, contador = 0;
    printf("El numero minimo es %d y se repite: ", min);
    for (i = 0; i < ce; i++)
    {
        if (ve[i] == min)
            contador++;
    }
    printf("%d veces\n", contador);
}

int BuscarMax(int ve[], int cant)
{
    int i, maximo;
    maximo = ve[0];
    for (i = 1; i < cant; i++)
    {
        if (ve[i] > maximo)
        {
            maximo = ve[i];
        }
    }
    return maximo;
}

void MostrarMaximo(int ve[], int max, int ce)
{
    int i;
    printf("El maximo es %d y se encuentra en las posiciones", max);
    for (i = 0; i < ce; i++)
    {
        if (ve[i] == max)
        {
            printf(" %d", i + 1);
        }
    }
}