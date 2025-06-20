/*1.4 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado
de mayor a menor por nota.*/

#include <stdio.h>

void IngresoDatos(int[], int[], int);
int BuscarDuplicado(int[], int, int);
void Ordenar(int[], int[], int);
int main()
{
    int DNI[6], NOTA[6];
    IngresoDatos(DNI, NOTA, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("el alumno con DNI %d obtuvo una nota de %d\n", DNI[i], NOTA[i]);
    }

    Ordenar(DNI, NOTA, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("El alumno con Dni %d obtuvo una nota de %d\n", DNI[i], NOTA[i]);
    }

    return 0;
}

void IngresoDatos(int ve[], int ve2[], int ce)
{
    int dni, notas, i = 0, pos;
    printf("Ingrese DNI: ");
    scanf("%d", &dni);
    while (dni > 0 && i < ce)
    {
        pos = BuscarDuplicado(ve, dni, i);
        if (pos == -1)
        {
            printf("Ingrese Nota: ");
            scanf("%d", &notas);
            ve[i] = dni;
            ve2[i] = notas;
            i++;
            printf("Ingrese DNI: ");
            // scanf("%d", &dni);
        }
        else
        {
            printf("DNI duplicado, ingrese otro: ");
            scanf("%d", &dni);
        }
    }
}

int BuscarDuplicado(int vector[], int datobuscar, int ce)
{
    int i = 0, pos = -1;
    while (i < ce && pos == -1)
    {
        if (vector[i] == datobuscar)
        {
            pos = i;
        }
        else
        {
            i++;
        }
    }
    return pos;
}

void Ordenar(int ve1[], int ve2[], int tam)
{
    int i, aux, aux2, maximo;
    for (i = 0; i < tam - 1; i++)
    {
        maximo = i;
        for (int j = i + 1; j < tam; j++)
        {
            if (ve2[j] > ve2[maximo])
            {
                maximo = j;
            }
        }
        if (maximo != i)
        {
            aux = ve2[i];
            ve2[i] = ve2[maximo];
            ve2[maximo] = aux;

            aux2 = ve1[i];
            ve1[i] = ve1[maximo];
            ve1[maximo] = aux2;
        }
    }
}