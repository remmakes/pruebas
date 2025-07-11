/*Ejercicio 1. Como resultado de un proceso eleccionario, se cuenta con los resulttados finales
de cada una de las mesas que participaron en las ultimas elecciones en CABA. Al finalizar el recuento
de la cantidad de votos de cada mesa,se nos entrega una planilla con los siguientes datos:
  - Numero de comuna (del 1 a 15)
  - Numero de Lista(del 1 al 17)
  - Cantidad de votos(int)
Dichos datos se ingresaran por teclado en forma desordenada almacenandose en una matriz, hasta la lectura
de un numero de comuna 0(cero).Los numeros de comuna y de lista se deben validar en forma separada a traves
de una unica funcion con parametros.

Confeccionar la codificacion en lenguaje "C" para:
a)Informar el/los numero/s de comuna y numero/s de lista que finalizaron con la menor cantidad de votos,
distinto de cero.Mostrar la menor cantidad de votos en una oportunidad y todas las combinaciones (comuna/lista)
que finalizaron con cantidades de votos iguales al minimo.
b)Informar las cantidades totatles de votos por comuna
c)Informar el numero de lista ganadora(el mayor es unico)
d)Mostrar la cantidad de votos de la lista numero 10 de cada comuna ordenados de mayor a menor.Se debe visualizar
el numero de comuna y la cantidad de votos.Para el ordenamiento utilizar una funcino*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leyvalida(int,int);
void cargadatos(int [][]);
void MenorV(int [][]);
void Cantidadtotal(int [][]);
void Listaganadora(int [][]);

int main()
{
    int votaciones[15][17]={{0}};
    cargadatos(votaciones);
    MenorV(votaciones);
    Cantidadtotal(votaciones);
    Listaganadora(votaciones);

    return 0;
}

int leyvalida(int li,int ls)
{
    int x,band=0;
    do
    {
        if (band==1)
        {
            printf("Codigo incorrecto");
        }
        band=1;
        scanf("%d",&x);
    } while (x<li || x>ls);
    return x;
}

void cargadatos(int votaciones [][17])
{
    int comunaaux,listaaux,votos;
    printf("Ingrese numero de comuna; ");
    comunaaux=leyvalida(0,15);
    while (comunaaux!=0)
    {
        printf("\nIngrese numero de lista: ");
        listaaux=leyvalida(1,17);
        printf("\nIngrese cantidad de votos: ");
        scanf("%d",&votos);
        votaciones[comunaaux-1][listaaux-1]+=votos;

        printf("Ingrese numero de comuna; ");
        comunaaux=leyvalida(0,15);
    }    
}

/*a)Informar el/los numero/s de comuna y numero/s de lista que finalizaron con la menor cantidad de votos,
distinto de cero.Mostrar la menor cantidad de votos en una oportunidad y todas las combinaciones (comuna/lista)
que finalizaron con cantidades de votos iguales al minimo.*/
void MenorV(int votaciones[][17])
{
    int menor=0;
    for (int i = 0; i < 15 && menor==0; i++)
    {
        for (int j = 0; j < 17 && menor==0; j++)
        {
            if (votaciones[i][j]!=0)
            {
                menor=votaciones[i][j];
            }
        }
    }
    
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (votaciones[i][j]<menor && votaciones[i][j]!=0)
            {
                menor=votaciones[i][j];
            }   
        }        
    }
    printf("\nLa menor cantidad de votos fue de %d ",menor);
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (votaciones[i][j]==menor)
            {
                printf("Comuna %d, lista %d",i+1,j+1);
            }   
        }    
    }
}

//b)Informar las cantidades totales de votos por comuna
void Cantidadtotal(int votaciones [][17])
{
    int i,j;
    int cantt[15]={0};
    for ( j = 0; j < 15; j++)
    {
        for ( i = 0; i < 17; i++)
        {
            cantt[j]+=votaciones[j][i];
        }    
    }
    for ( j = 0; j < 15; j++)
    {
        printf("La comuna %d obtuvo %d votos",j+1,cantt[j]);
    }    
}

//c)Informar el numero de lista ganadora(el mayor es unico)
void Listaganadora(int votaciones[][17])
{
    int i,j,max=votaciones[0][0],listag;
    for ( i = 0; i < 15; i++)
    {
        for(j=0;j<17;j++)
        {
            if (votaciones[i][j]>max)
            {
                max=votaciones[i][j];
                listag=j;
            }
            
        }
    }
    printf("\nLa lista ganadora fue %d con %d votos",listag+1,max);
}