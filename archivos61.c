/*6.1 Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA*/

#include <stdio.h>
#include <string.h>

typedef struct 
{
    int dni;
    char apynm[80];
    int n1,n2;
    float promedio;
}sComputacion;

int main ()
{
    sComputacion alumno;
    FILE *arch;
    arch= fopen("ALUMNOS.dat","wb");
    if (arch==NULL)
    {
        printf("Archivo inexistente");
        getch ();
        exit (1);
    }
    printf("Ingrese DNI: ");
    scanf("%d",&alumno.dni);
    while (alumno.dni!=0)
    {
        getchar();
        printf("\nIngresar Nombre y Apellido: ");
        gets(alumno.apynm);
        printf("Ingrese nota 1: ");
        scanf("%d",&alumno.n1);
        printf("Ingrese nota 2: ");
        scanf("%d",&alumno.n2);
        alumno.promedio=(alumno.n1+alumno.n2)/2;
        fwrite(&alumno,sizeof(sComputacion),1,arch);

        printf("Ingrese DNI: ");
        scanf("%d",&alumno.dni);
    }
    fclose(arch);
    
    return 0;
}

