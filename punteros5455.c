/*5.4 Hacer un programa que cargue un vector de 10 enteros y lo muestre usando una función para cargar y otra
mostrar sin utilizar subíndices.
5.5 Al programa anterior agregarle una función que reciba la dirección de inicio del vector y un número a buscar
y retorne un puntero al dato encontrado o NULL sino lo encuentra. En el main agregar un proceso de
búsqueda que se repita hasta ingresar un número negativo o cero a buscar. Si se lo encontró se debe
indicar en que posición del vector estaba (calcular dicha posición utilizando la dirección retornada)*/

#include <stdio.h>

void Carga(int *);
void Mostrar (int *);
int *Buscar(int*,int);

int main ()
{
    int Vector[10],num, *pP;
    int *resultado;
    pP= Vector;
    Carga(pP);
    Mostrar(pP);
    printf("\nIngrse que numero desea buscar: ");
    scanf("%d",&num);
    while (num>0)
    {
        resultado= Buscar(pP,num);
    if (resultado==NULL)
    {
        puts("\nNo se encontro el numero");
    }
    else
    {
        printf("\nNumero encontra en la posicion: %d",(resultado-Vector)+1);    
    }
    printf("\nIngrse que numero desea buscar: ");
    scanf("%d",&num);
    }
    return 0;
}

void Carga (int *puntero)
{
    int i;
    for ( i = 0; i < 10; i++)
    {
        printf ("Cargue un numero: ");
        scanf("%d",puntero);
        puntero++;
    }
}

void Mostrar(int *puntero)
{
    int i;
    for ( i = 0; i < 10; i++)
    {
        printf("\n%d",*(puntero+i));
    }    
}

int *Buscar(int *p,int nb)
{
    int i;
    for ( i = 0; i < 10; i++)
    {
        if (nb==*(p+i))
        {
            return p+i;
        }        
    }
    return NULL;
}
