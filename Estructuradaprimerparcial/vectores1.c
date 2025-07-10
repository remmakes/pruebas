/*1.1 Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menor(int *);
void Mayor(int *);
int main()
{
    int vector[20],i;
    int *pP;
    pP=vector;
    srand(time(NULL));
    for ( i = 0; i < 20; i++)
    {
        vector[i]=rand()%900+100;
    }
    
    for ( i = 0; i < 20; i++)
    {
        printf("\n%d",*(pP+i));
    }
    Menor(pP);
    Mayor(pP);
    return 0;
}

//a. Mostrar el menor valor e indicar cuantas veces se repite
void Menor(int *puntero)
{
    int menor,i,contador=0;
    menor=*puntero;
    for ( i = 0; i < 20; i++)
    {
        if (*(puntero+i)<menor)
        {
            menor=*(puntero+i);
        }else if (*(puntero+i)==menor)
        {
            contador++;
        }
    }
    printf("\nEl menor es: %d y se repite %d veces",menor,contador);
}

//b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra*/
void Mayor(int *puntero)
{
    int i,max;
    max=*puntero;
    for ( i = 0; i < 20; i++)
    {
        if (*(puntero+i)>max)
        {
            max=*(puntero+i);
        }
    }
    printf("\nEl mayor es: %d y se aparece en la/s posicion/es  ",max);
    for ( i = 0; i < 20; i++)
    {
        if (*(puntero+i)==max)
        {
            printf("%d",i+1);
        }   
    }
}