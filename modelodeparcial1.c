#include <stdio.h>

int main (){

    char letra;
    do
    {
        printf("Ingrese una letra minuscula: ");
        scanf ("%c",&letra);
        
    } while (letra < 'a'|| letra >'z');
    
}