/*7.4 Construir una función que reciba dos vectores enteros de igual tamaño y retorne un 1 si son guales o un 0
sino lo son*/

#include <stdio.h>

int vectoresT(int [],int [],int);

int main ()
{
    int size;
    printf("Ingrese el tamanio de los vectores: ");
    scanf("%d",&size);
    int vec1[size],vec2[size],val;
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&vec1[i]);
    }
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&vec2[i]);
    }
    val=vectoresT(vec1,vec2,size);
    if (val==1)
    {
        printf("Los vectores son iguales");
    }
    else    printf("No son iguales");
    
    return 0;
}

int vectoresT(int vec1[],int vec2[],int size)
{
    for (int i = 0; i < size; i++)
    {
        if (vec1[i]!=vec2[i])
        {
            return 0;
        }
        else    return 1;   
    }    
}