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
#include <stdlib.h>
#include <ctype.h>
typedef struct 
{
    int dni;
    char apynm[81];
    int n1,n2;
    float promedio;
}sComputacion;

int main ()
{
    sComputacion alumno;
    FILE *arch;
    arch= fopen("ALUMNOS.dat","w+b");//r+b es lectura y escritura , pero el archivo debe existir, w+b es lectura y escritura pero crea el archivo
    if (arch==NULL)
    {
        printf("Archivo inexistente");
        getchar ();
        exit (1);
    }
    printf("Ingrese DNI: ");
    scanf("%d",&alumno.dni);
    while (alumno.dni!=0)
    {
        getchar();
        printf("\nIngresar Nombre y Apellido: ");
        fgets(alumno.apynm,81,stdin);
        int largo=strlen(alumno.apynm);
        if (alumno.apynm[largo-1]=='\n')
        {
            alumno.apynm[largo-1]='\0';
        }
        
        printf("\nIngrese nota 1: ");
        scanf("%d",&alumno.n1);
        printf("\nIngrese nota 2: ");
        scanf("%d",&alumno.n2);
        alumno.promedio=(alumno.n1+alumno.n2)/2;
        fwrite(&alumno,sizeof(sComputacion),1,arch);

        printf("Ingrese DNI: ");
        scanf("%d",&alumno.dni);
    }
    rewind(arch);
    fread(&alumno,sizeof(sComputacion),1,arch);
    while (!feof(arch))//
    {
        printf("DNI: %d, Apellido y Nombre: %s,Nota1: %d, Nota 2: %d,Promedio: %.2f\n",alumno.dni,alumno.apynm,alumno.n1,alumno.n2,alumno.promedio);
        fread(&alumno,sizeof(sComputacion),1,arch);
    }
    
    fclose(arch);
    
    return 0;
}

