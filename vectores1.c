/*7.1 Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere un
vector de 10 posiciones con el contenido de ambos vectores uno a continuación del otro. Mostrar el vector
generado.*/

#include<stdio.h>

void vectorT (int [], int [], int);

int main ()
{   
    int vec[5],vec2[5];
    for (int i = 0; i < 5; i++)
    {
        printf ("Ingrese un numero:");
        scanf("%d",&vec[i]);     
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese otros 5 numeros: ");
        scanf("%d",&vec2[i]);
    }   
    vectorT(vec,vec2,10);
  /*  for (int j = 0; j < 5; j++)
    {
        vect[j]=vec[j];
        vect[j+5]=vec2[j];
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d",vect[i]);
    }
    */
    return 0;
}

void vectorT (int vec[],int vec2[],int n)
{
    int vect[10];
    for (int i = 0; i < 5; i++)
    {
        vect[i]=vec[i];
        vect[i+5]=vec2[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d",vect[i]);
    }
     
}

