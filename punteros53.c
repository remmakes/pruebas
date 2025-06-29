/*5.3 Realizar una función que permita ingresar por teclado un valor entero, un flotante y un carácter. La función
no debe retornar ningún valor. Las variables se declaran y se muestran en el programa principal*/

#include <stdio.h>

int main()
{
    int num,*pn;
    float cod,*pcod;
    char letra,*pletra;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    pn=&num;
    printf("\nIngrese un flotanto: ");
    scanf("%f",&cod);
    pcod= &cod;
    getchar();
    printf("\nIngrese una letra: ");
    scanf("%c",&letra);
    pletra=&letra;

    printf("\nEl numero es %d, el flotante es %.2f, la letra es %c",*pn,*pcod,*pletra);
    return 0;
}