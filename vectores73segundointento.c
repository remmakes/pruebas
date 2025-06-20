/*7.3 Realizar los siguientes vectores con 10 valores reales. Confeccionar un programa para:
a. Generar el vector VA con la información ingresada por teclado.
b. Generar el vector VB, donde cada elemento es la raíz cuadrada del respectivo elemento de VA.
(para el cálculo de la raíz cuadrada utilizar la función sqrt disponible en la biblioteca math.h). Si el
número es negativo poner un 0 ya que no se puede calcular la raíz
c. Calcular el vector VC como VA+VB.
d. Copiar el vector VC en orden inverso en otro vector llamado VD.
e. Hallar el valor máximo del vector VA y en qué posición se halló (el mayor es único).
f. Generar un vector VE con aquellos valores negativos que se encuentran en el vector VA.
g. Mostrar el contenido de todos los vectores.
FUNCIONES:
I. Para el ingreso del vector AA, del punto a.
II. Para generar el vector CC, del punto c.
III. Para generar el vector VE del punto g.
IV. Para mostrar los valores de todos los vectores del punto h.*/

#include<stdio.h>
#include<math.h>
int vectorVA ();
void vectorVC (int [],float [],float []);
int main ()
{
    int VA[5], max,band=0,posicion=0,VE[5];
    float VB[5],VC[5],VD[5];
    for (int i = 0; i < 5; i++)
    {
        VA[i]=vectorVA();
        VB[i]=sqrt(VA[i]);//b. Generar el vector VB, donde cada elemento es la raíz cuadrada del respectivo elemento de VA     
    }

    vectorVC (VA,VB,VC); //vectorVC(VA,VB);
    
    for (int i = 0; i < 5; i++)
    {
        VD[i]=VC[4-i]; //Copiar el vector VC en orden inverso en otro vector llamado VD.
    }
    //e. Hallar el valor máximo del vector VA y en qué posición se halló (el mayor es único).
    for (int i = 0; i < 5; i++)
    {        
        if (band==0 || VA[i]>max)
        {
            max=VA[i];
            band=1;
            posicion=i+1;
        }        
    }
    //printf("max %d en la posicion %d",max,posicion);
    //f. Generar un vector VE con aquellos valores negativos que se encuentran en el vector VA.
    
    return 0;
}

int vectorVA()
{
    int x;
    printf("Ingrese un valor:");
    scanf("%d",&x);
    return x;
}

void vectorVC (int va[],float vb[],float vc[])
{
    for (int i = 0; i < 5; i++)
    {
        vc[i]=va[i]+vb[i];
    }
}