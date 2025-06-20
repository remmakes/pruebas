/*Un call center tiene 50 agentes numerados del 201 al 250 y se ingresa por cada uno
en forma secuencial al principio del proceso, el numero de grupo donde trabaja (de 1 a 8)
este punto debe resolverse utilzando la funcion IngresaDatoVal(parametros requeridos)

Luegos se ingresa cada agente los datos de la camapa;a diaria conteniendo
* Numero de agente
* Cant contactos (entero mayor a 0)
La carga termina con un agente igual a cero. Es psobiel que un agente no tenga contactos
hechos . Deben validarse todos lso datos segun su especificacion

Confeccionar un programa que informe:

A) Cantidad contactada en total por cada agente informando su numero y cantidad (resolver
en funcion llamada mostrarContactados())
B)EL promedio de cantidad de contactos realizados por cada agente del grupo 7
C)Listar mediante una funcion la cantidad de agentes de cada grupo*/


#include<stdio.h>

int IngresaDatoVal(int,int,int);
int Contactos(int);
void mostrarContactados(int[],int[],int []);
void AgentesxGrupo(int [],int []);
int main()
{
    int agentes [5] ,grupo[5],agente,contact[5]={0};;
    //IngreseDatoVal(201,250);
    for (int i = 0; i < 5; i++)
    {
        agentes[i]=IngresaDatoVal(201,250,201);
        grupo[i]=IngresaDatoVal(1,8,1);
    }
    
    //do
    //{   
        printf("Ingrese un agente: ");
        agente=IngresaDatoVal(201,250,0);
        while (agente!=0)
        {
            printf("\nCantidad de contactos: ");
            contact[agente-201]+=Contactos(0);
            printf("Ingrese un agente: ");
            agente=IngresaDatoVal(201,250,0);
        }
        
        
    //} while (agente!=0);

    mostrarContactados(contact,agentes,grupo);
    AgentesxGrupo (agentes,grupo);
    /*printf A) Cantidad contactada en total por cada agente informando su numero y cantidad (resolver
    en funcion llamada mostrarContactados())
    B)EL promedio de cantidad de contactos realizados por cada agente del grupo 7
    C)Listar mediante una funcion la cantidad de agentes de cada grupo*/
}

int IngresaDatoVal(int li,int ls,int cierre) //fx que valida el grupo!
{
    int x,band=0;
    do
    {
        if(band==1)
        {
            printf("No es CORRECTO");
        }
        band=1;
        printf("Ingrese valor: ");
        scanf("%d",&x);
    } while ((x<li || x>ls) && x!=cierre);
    return x;
}

int Contactos(int n)
{
    int y;
    scanf("%d",&y);
    if(y>0)
    {
        return y;
    }
    else printf("Cantidad de contactos NO VALIDA");
    
}

void mostrarContactados(int vector1[],int vector2[],int vector3 [])
{
    int cont1=0,acumula=0;
    for (int i = 0; i < 5; i++)
    {
        
        printf("\nCantidad contactada %d por agente %d ",vector1[i],vector2[i]);
        if (vector3[i]==7)
        {
            cont1++;
            acumula+=vector1[i];
        }
        
    }
    printf("\nEl promedio de contactos por agentes de grupo 7 es %.2f",(float)acumula/cont1);
    
}

//C)Listar mediante una funcion la cantidad de agentes de cada grupo*/
void AgentesxGrupo(int agentx[],int grupox[])
{
    int cont1[8]={0};
    for (int i = 0; i < 5; i++)
    {
        switch (grupox[i])
        {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            cont1[grupox[i]-1]++;
            break;
        
        default:
            break;
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        printf("\ngrupo %d es igual a %d:\n",i,cont1[i-1]);
    }
    
    
}