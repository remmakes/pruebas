/*6.4. Se ingresa valores positivos entre 1 y 50, finalizando el ingreso con el valor -10, para ello generar una función
que valide dicho ingreso. Calcular:
a. Cuántos números son primos.
b. Cantidad de números pares.
c. Promedio de los números impares.
Utilizar las siguientes funciones:
• Resto: recibe por parámetro el Dividendo y el Divisor; Retorna el resto.
• EsPar: recibe por parámetro un número; Retorna 1 si es Par, 0 si es Impar; Invoca a la función Resto.
• EsPrimo: recibe por parámetro un número; Retorna 1 si es primo, 0 si no es primo; Invoca a la
función Resto. (un número es primero si solo es divisible por 1 y por sí mismo).
• Promedio: recibe por parámetro la suma y el contador; Retorna el promedio si contador > 0 sino
Retorna 0.
*/

#include<stdio.h>

int leyvalida (int,int,int);
int resto (int, int);
int EsPar (int);
int EsPrimo (int);
float Promedio (float,float);

int main()
{
    int valor,cont1=0,cont2=0,cont3=0,acumu1=0;
    do
    {
        printf("Ingrese un numero: ");
        valor=leyvalida(1,50,-10);
        while (valor!=-10)
        {
            if (EsPar(valor))
            {
                cont1++;
            }
            else 
            {
                cont2++;
                acumu1+=valor;
                
            }
            if (EsPrimo(valor))
            {
                cont3++;
            }
               
        }
        
        
    } while (valor!=-10);
        
    printf("Cantidad de numeros primos: %d",cont3);
    printf("\n Cantidad de numeros pares: %d",cont1);
    printf("\n Promedio de numeros impares: %.2f",Promedio(acumu1,cont2));


    return 0;
}

int leyvalida (int li,int ls,int cierre)
{
    int x,band=0;
    do{
        if (band==1)
        {
            printf("VALOR FUERA DE RANGO");
        }
        band=1;
        scanf("%d",&x);
    }while ((x<li || x>ls)&& x!=cierre);
    return x;
}

int resto (int dividendo, int divisor)
{
    return dividendo%divisor;
}

int EsPar (int par)
{
    if(resto(par,2)==0)
    { 
        return 1;
    }
    else return 0;
}

int EsPrimo (int numero)
{
    if(numero<=1)
    {
        return 0;
    }else{}
    for(int i=2;i*i<=numero;i++)
    {
        if(resto(numero,i)==0)
        {
            return 0;
        }
    }
    return 1;
}

float Promedio (float suma,float contador)
{
    if(contador>0)
    {
        return suma/contador;
    }
    else return 0;
    
}