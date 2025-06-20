/*7.2 Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere un
vector de 10 posiciones con el contenido de ambos vectores intercalados. Mostrar el vector generado*/

#include <stdio.h>

void vectorT (int [],int [],int [],int);

int main ()
{
    int vec[5],vec2[5],result[10];
    for (int i = 0; i < 5; i++)
    {
        printf ("Ingrese un numero: ");
        scanf("%d",&vec[i]);
        printf("Ingrese otro numero: ");
        scanf ("%d",&vec2[i]);
    }
    vectorT(vec,vec2,result,10);
    return 0;
}

void vectorT (int vec[],int vec2[],int result [],int n)
{
    for (int i = 0; i < n; i++)
    {
        result[2*i]=vec[i];
        result[2*i+1]=vec2[i];
        printf("%d",result[i]) ;
    }
     
}