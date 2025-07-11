/*6.2 Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea desarrollar un
programa que, basado en la información del archivo, genere 3 archivos:
• Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
• Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no
promocionados).
• Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre del archivo
a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para mostrar todos los
archivos generados.*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct {
    int dni;
    char apynm[81];
    int n1, n2;
    float promedio;
} sComputacion;

void mostrararchivo (char* nombre);

int main()
{
    sComputacion alumnos;
    FILE* archivo;
    FILE* PROMOCIONADOS;
    FILE* CURSADO;
    FILE* REPROBADOS;
    archivo=fopen("ALUMNOS.dat","rb");

    if (archivo==NULL)
    {
        printf("Archivo inexistente");
        getchar ();
        exit (1);
    }
    PROMOCIONADOS=fopen("PROMOCIONADOS.dat","wb");
    CURSADO=fopen("CURSADO.dat","wb");
    REPROBADOS=fopen("REPROBADOS.dat","wb");
    fread(&alumnos,sizeof(sComputacion),1,archivo);
    while(!feof(archivo))
    {
        if (alumnos.n1>=7 && alumnos.n2>=7)
        {
            fwrite(&alumnos,sizeof(sComputacion),1,PROMOCIONADOS);
        }
        else if (alumnos.n1 >= 4 && alumnos.n2 >= 4)
        {
            fwrite(&alumnos,sizeof(sComputacion),1,CURSADO);
        }
        else
        {
            fwrite(&alumnos,sizeof(sComputacion),1,REPROBADOS);
        }
        fread(&alumnos,sizeof(sComputacion),1,archivo);        
    }
    fclose(archivo);
    fclose(PROMOCIONADOS);
    fclose(CURSADO);
    fclose(REPROBADOS);
    mostrararchivo("PROMOCIONADOS.dat");
    mostrararchivo("CURSADO.dat");
    mostrararchivo("REPROBADOS.dat");

    return 0;
}

void mostrararchivo(char* nombre)
{
    FILE* archivo;
    sComputacion alumnos;
    archivo=fopen(nombre,"rb");
    if (archivo==NULL)
    {
        printf("No se puede abrir el archivo: %s",nombre);
        return;
    }

    fread(&alumnos,sizeof(sComputacion),1,archivo);
    while (!feof(archivo))
    {
        printf("DNI: %d, Apellido y nombre: %s, Nota1: %d,Nota2: %d, Promedio: %.2f\n",alumnos.dni,alumnos.apynm,alumnos.n1,alumnos.n2,alumnos.promedio);
        fread(&alumnos,sizeof(sComputacion),1,archivo);
    }
    fclose(archivo);    
}
