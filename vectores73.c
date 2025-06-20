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

int vectorVA (int []);
int vectorVB (int []);
int vectorVC (int [],int []);

int main()
{   
    int va[10],vb[10],vectorc[10];
    vectorVA(va); 
    vectorVB(va);
    for (int i = 0; i < 10; i++)
    {
        vectorc[i]=va[i]+vb[i];
        printf("%d",vectorc[i]);
    }
    
   
    return 0;
}

int vectorVA(int va[])
{
    for (int i = 0; i < 10; i++)
    {
        
        printf("Ingrese un numero: ");
        scanf ("%d",&va[i]);
        
    }
    return va;
}

int vectorVB(int vectorVA [])
{
    float vectorB[10];
    
    //Si el número es negativo poner un 0 ya que no se puede calcular la raíz
    for (int i = 0; i < 10; i++)
    {
        if (vectorVA[i]>0)
        {
            vectorB[i]=(float)sqrt(vectorVA[i]);           
        }
        else 
        {
           vectorB[i]=0;
        }
        printf("%.2f ",vectorB[i]);
         
    }  
    return vectorB; 
}

/*int vectorVC (int vectorVA[],int vectorVB[])
{
    int vc[10];
    for (int i = 0; i < 10; i++)
    {
        vc[i]=vectorVA[i]+vectorVB[i];
        return vc;
    }
    

}*/