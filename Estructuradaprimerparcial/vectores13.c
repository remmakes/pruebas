/*1.3 En un curso de la maestría en informática los estudiantes deben exponer en forma grupal sus investigaciones
de un tema dado. El curso está formado por 5 grupos. Se pide realizar un programa para sortear el orden de
exposición de dichos grupos. Cada vez que se ejecute el programa deberá mostrar un orden de exposición
distinto para cada uno de los 5 grupos.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main ()
{
    srand(time(NULL));
    int grupos[5]= {1,2,3,4,5};
    int j,aux,i;
    for ( j = 4; j >0; j--)
    {
        i= rand()% (j+1);

        aux=grupos[i];
        grupos[i]=grupos[j];
        grupos[j]=aux;
    }
    
    printf("El orden de exposicion es: ");
    for ( i = 0; i < 5; i++)
    {
        printf("\n%d Grupo numero: %d",i+1,grupos[i]);
    }
    
         
    return 0;
}