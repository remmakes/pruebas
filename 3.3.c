/*3.3 Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor*/

#include <stdio.h>
#include <string.h>

void ingresardatos(char[][20], int[]);
int Buscarduplicado(char[][20], char[], int);
void Ordenar(char[][20], int[], int);
int main()
{
    char nombre[5][20], dato[20];
    int dni[5], i = 0, pos, largo;
    ingresardatos(nombre, dni);
    puts("Ingrese un nombre");
    fgets(dato, 20, stdin);
    largo = strlen(dato);
    if (dato[largo - 1] == '\n')
    {
        dato[largo - 1] = '\0';
    }
    while (strcmpi(dato, "NOBUSCARMAS") != 0)
    {
        pos = Buscarduplicado(nombre, dato, 5);
        if (pos != -1)
        {
            printf("El dni es %d\n", dni[pos]);
        }
        else if (pos == -1)
        {
            puts("No se encuentra ese alumno");
        }

        printf("Ingrese otro nombre: ");
        fgets(dato, 20, stdin);
        largo = strlen(dato);
        if (dato[largo - 1] == '\n')
        {
            dato[largo - 1] = '\0';
        }
    }
    Ordenar(nombre, dni, 5);

    for (i = 0; i < 5; i++)
    {
        printf("El alumno %s, tiene DNI: %d\n", nombre[i], dni[i]);
    }

    return 0;
}

void ingresardatos(char nombres[][20], int dnis[])
{
    int i = 0, largo;
    puts("Ingrese nombre");
    fgets(nombres[i], 20, stdin);
    largo = strlen(nombres[i]);
    if (nombres[i][largo - 1] == '\n')
    {
        nombres[i][largo - 1] = '\0';
    }

    while (strcmpi(nombres[i], "fin") != 0 && i < 5)
    {
        puts("Ingrese DNI");
        scanf("%d", &dnis[i]);
        while (getchar() != '\n')
            ;
        i++;

        if (i < 5)
        {
            puts("Ingrese nombre");
            fgets(nombres[i], 20, stdin);
            largo = strlen(nombres[i]);
            if (nombres[i][largo - 1] == '\n')
            {
                nombres[i][largo - 1] = '\0';
            }
        }
    }
}

int Buscarduplicado(char nombres[][20], char datobuscado[], int ce)
{
    int i = 0, pos = -1;
    while (pos == -1 && i < ce)
    {
        if (strcmpi(nombres[i], datobuscado) == 0)
        {
            pos = i;
        }
        else
            i++;
    }
    return pos;
}

void Ordenar(char nombres[][20], int dnis[], int ce)
{
    char auxi[20];
    int aux;
    for (int i = 0; i < ce - 1; i++)
    {
        for (int j = 0; j < ce - 1 - i; j++)
        {
            if (strcmpi(nombres[j], nombres[j + 1]) > 0)
            {
                strcpy(auxi, nombres[j]);
                strcpy(nombres[j], nombres[j + 1]);
                strcpy(nombres[j + 1], auxi);

                aux = dnis[j];
                dnis[j] = dnis[j + 1];
                dnis[j + 1] = aux;
            }
        }
    }
}