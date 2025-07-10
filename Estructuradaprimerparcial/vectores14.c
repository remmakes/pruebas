/*1.4 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado
de mayor a menor por nota.*/

#include <stdio.h>
#include <stdlib.h>

int BusquedaD(int [],int,int);
void Ordenamiento(int [],int [],int);

int main()
{
    int dni[60],nota[60];
    int i=0,duplicado;
    printf("Ingrese DNI del alumno: ");
    scanf("%d",&dni[i]);
    while (dni[i]>0 && i<60)
    {
        duplicado=BusquedaD(dni,i,dni[i]);
        if (duplicado==-1)
        {
            printf("\nIngrese la nota: ");
            scanf("%d",&nota[i]);
            i++;
        }

        printf("Ingrese DNI del alumno: ");
        scanf("%d",&dni[i]);
    }
    Ordenamiento(dni,nota,i);
    
    return 0;
}

int BusquedaD(int dni[],int ce,int eb)
{
    int i=0,pos=-1;
    while (pos==-1 && i<ce)
    {
        if (dni[i]==eb)
        {
            pos=i;
        }else
            i++;
    }
    return pos;
}

void Ordenamiento(int dni[],int nota[],int ce)
{
    int i,j,aux1,aux2,mayor;
    mayor=nota[0];
    for ( i = 0; i < ce-1; i++)
    {
        for ( j = 0; j < ce-1-i; j++)
        {
            if (nota[j]<nota[j+1])
            {
                aux1=nota[j];
                nota[j]=nota[j+1];
                nota[j+1]=aux1;

                aux2=dni[j];
                dni[j]=dni[j+1];
                dni[j+1]=aux2;
            }   
        }   
    }
    
    for ( i = 0; i < ce; i++)
    {
        printf("\nEl alumno con DNI %d, obtuvo %d",dni[i],nota[i]);
    }
    
}