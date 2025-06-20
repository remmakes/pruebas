/*7.6 Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como
máximo la empresa tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un
empleado con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función
CuentaPorSector y mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.*/

#include<stdio.h>

void CargaEmpleados (int [],int [],int [],int);
int leyvalida(int,int,int);
void CuentaPorSector(int [],int);
int main()
{   
    int n;
    scanf("%d",&n);
    int Empleado[n],sector[n],sueldo[n];
    Cargaempleados(Empleado,sector,sueldo,n);   
    CuentaPorSector (sector,n);
    return 0;
}

void CargaEmpleados(int n [],int m[],int l[],int limite)
{
    int DNI,codigosector,sueldo,i=0;
   
        printf("Ingrese DNI: ");
        n[i]=leyvalida(1,9999999,99);
        while (n[i]!=99 || i<=99)
        {            
            printf("\nIngrese codigo de sector:");
            m[i]=leyvalida(1,5,1);
            printf("\nIngrese el sueldo: ");
            scanf("%d",&l[i]);
            i++;
            printf("\nIngrese DNI: ");
            n[i]=leyvalida(1,9999999,99);
        }
    
}

int leyvalida (int li,int ls,int cierre)
{
    int x,band=0;
    do
    {
        if (band==1)
        {
            printf("Fuera de rango");
        }
        band=1;
        scanf("%d",&x);
    } while ((x<li || x>ls)&& x!=cierre);
    return x;
}

void CuentaPorSector (int sector[],int n)
{
    
}