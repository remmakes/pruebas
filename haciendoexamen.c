/*1) Se dispone de un archivo binario con el siguiente diseño de registro de los clientes de un banco:
- Número de cuenta (entero)
- Apellido y nombre (texto de 30 caracteres máximo)
- Saldo (float)
A continuación, se ingresan por teclado los siguientes datos
. Número de cuenta (entero)
. código de operación (1: deposito 2: extracción)
. importe (float)
Finalizando el ingreso al digitar un número de cuenta igual a cero.
Realizar un programa que permita actualizar los saldos de los clientes, según los códigos de operación e importes ingresados.
No se permiten que las cuentas queden con saldos negativos, por lo tanto, ante una extracción, de no ser posible la operación informar “Saldo insuficiente”
y pasar a ingresar el próximo número de cuenta.
En los casos que no exista un número de cuenta, informar “Número de cuenta inexistente” e ingresar el próximo número de cuenta.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int ncuenta;
    char apynm[31];
    float saldo;
}sRegistro;

void Operacion(FILE*,int);

int main ()
{
    sRegistro cliente;
    FILE* archivo;
    int numeroc;
    archivo=fopen("registro.dat","r+b");
    if (archivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }
    printf("Ingrese numero de cuenta: ");
    scanf("%d",&numeroc);
    while (numeroc!=0)
    {
        rewind(archivo);
        Operacion(archivo,numeroc);
        printf("Ingrese numero de cuenta: ");
        scanf("%d",&numeroc);
    }
    fclose(archivo);
    return 0;
}

void Operacion(FILE* archivo,int numeroc)
{
    sRegistro cliente;
    int encontrado=0,op,monto;
    fread(&cliente,sizeof(sRegistro),1,archivo);
    while (!feof(archivo))
    {
        if(numeroc==cliente.ncuenta)
        {
            encontrado=1;
            printf("\nQue desea realizar(1 para deposito,2 para extraccion): ");
            scanf("%d",&op);
            printf("\nIngrese monto: ");
            scanf("%d",&monto);
            if (op==1)
            {
                cliente.saldo+=monto;
            }else if (op==2)
            {
                if (cliente.saldo<monto)
                {
                    printf("\nSaldo insuficiente");
                }
                else
                    cliente.saldo-=monto;       
            }
            fseek(archivo,sizeof(sRegistro)*-1,SEEK_CUR);
            fwrite(&cliente,sizeof(sRegistro),1,archivo);
            fflush(archivo);            
        }

        fread(&cliente,sizeof(sRegistro),1,archivo);
    }
        if (encontrado==0)
    {
        printf("Cliente inexistente");
    }
}