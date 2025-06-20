/*7.1 Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere un
vector de 10 posiciones con el contenido de ambos vectores uno a continuación del otro. Mostrar el vector
generado.*/

#include <stdio.h>

void VectorT (int [],int[]);
int IngreseNUM ();

int main ()
{
    int vector1[5],vector2[5];
    for (int i = 0; i < 5; i++)
    {
        vector1[i]=IngreseNUM();
        vector2[i]=IngreseNUM();
    }
    VectorT(vector1,vector2);    

    return 0;
}

int IngreseNUM ()
{
    int x;
    printf("Ingrese un numero:");
    scanf("%d",&x);
    return x;
}

void VectorT (int v1[],int v2[])
{
    int vectorT[10];
    for (int i = 0; i < 5; i++)
    {
        vectorT[i]=v1[i];
        vectorT[i+5]=v2[i];
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d",vectorT[i]);
    }
}