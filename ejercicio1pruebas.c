/*1) Se dispone de un archivo binario con el siguiente diseño de registro de los clientes de un
banco:
- Número de cuenta (entero)
- Apellido y nombre (texto de 30 caracteres máximo)
- Saldo (float)
A continuación, se ingresan por teclado los siguientes datos
. Número de cuenta (entero)
. código de operación (1: deposito 2: extracción)
. importe (float)
Finalizando el ingreso al digitar un número de cuenta igual a cero.
Realizar un programa que permita actualizar los saldos de los clientes, según los códigos de
operación e importes ingresados.
No se permiten que las cuentas queden con saldos negativos, por lo tanto, ante una
extracción, de no ser posible la operación informar “Saldo insuficiente” y pasar a ingresar el
próximo número de cuenta.
En los casos que no exista un número de cuenta, informar “Número de cuenta inexistente” e
ingresar el próximo número de cuenta.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int ncuenta;
    char apynm[31];
    float saldo;
}sRegistro;

void Ingresoclientes (char*);

int main()
{
    sRegistro cliente;
    FILE *pf;
    int n_buscar,num;
    float importe;
    pf=fopen("registro.dat","wb");
    if (pf==NULL)
    {
        printf("Arhivo inexistente");
        exit (1);
    }
    Ingresoclientes("registro.dat");

    printf("Ingrse numero de cliente a buscar: ");
    scanf("%d",&n_buscar);
    while (n_buscar!=0)
    {
        rewind(pf);
        int encontrado=0;
        fread(&cliente,sizeof(sRegistro),1,pf);
        while (!feof(pf))
        {
            if (n_buscar==cliente.ncuenta)
            {
                encontrado=1;
                printf("\nIngrese codigo de operacion(1:para deposito,2:para extraccion): ");
                scanf("%d",&num);
                if (num==1)
                {
                    printf("\nIngrese importe: ");
                    scanf("%f",&importe);
                    cliente.saldo+=importe;
                }else if(num==2)
                {
                    printf("\Ingrese cuanto desea retirar");
                    scanf("%f",&importe);
                    if (importe<=cliente.saldo)
                    {
                        cliente.saldo-=importe;
                    }else{
                        printf("Saldo insuficiente");
                    }
                }
            fseek(pf,sizeof(sRegistro)*-1,SEEK_CUR);
            fwrite(&cliente,sizeof(sRegistro),1,pf);
            }
            

            fread(&cliente,sizeof(sRegistro),1,pf);
        }
        printf("Ingrse numero de cliente a buscar: ");
        scanf("%d",&n_buscar);
    }
    if (encontrado==0)
    {
                printf("Cliente inexistente");
            }
    
    return 0;
}

void Ingresoclientes(char *cd)
{
    sRegistro carga;
    FILE* arch;
    arch=fopen(cd,"a+b");
    printf("Ingrese numero de cuenta: ");
    scanf("%d",&carga.ncuenta);
    while (carga.ncuenta!=0)
    {
        getchar();
        printf("Ingrese Apellido y Nombre: ");
        gets(carga.apynm);
        printf("Ingrese Saldo: ");
        scanf("%f",&carga.saldo);
        fwrite(&carga,sizeof(sRegistro),1,arch);

        printf("Ingrese numero de cuenta: ");
        scanf("%d",&carga.ncuenta);
    }
    fclose(arch);
}