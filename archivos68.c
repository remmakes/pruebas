/*6.8 Se dispone de un archivo que contiene información de los vuelos realizados por las distintas aerolíneas a lo
largo del mes. El archivo se denomina Vuelos.dat y guarda los registros con la siguiente estructura:
• Código Aerolínea (alfanumérico de 10 caracteres máximo)
• Día (entero)
• Número de Vuelo (entero)
• Costo del pasaje (real)
• Pasajeros (inicialmente en el archivo viene en 0)
Luego se dispone de un segundo archivo llamado Pasajeros.dat que incluye la información de los viajeros del mes
para la aerolínea con código “Aero1”, el archivo contiene los siguientes campos:
• DNI (entero)
• Número de Vuelo (entero)
Se desea realizar un programa que actualice la cantidad de pasajeros de la aerolínea con código “Aero1”
con la información de los pasajeros que realizaron los viajes. Tenga en cuenta que los números de vuelo se
repiten entre las distintas aerolíneas. Al finalizar dar la opción para exportar los datos de vuelo de Aero1 en
formato csv.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char cod[11];
    int dia;
    int numvuelo;
    float costop;
    int pasajeros;
}sRegistro;

typedef struct 
{
    int dni;
    int numv;
}sAero;

void Actualizo(FILE *,FILE *,char);

int main ()
{
    sRegistro vuelo;
    sAero pasajero;
    FILE* archivo, *archpasajero;
    archivo=fopen("Vuelos.dat","r+b");
    archpasajero=fopen("Pasajeros.dat","rb");
    if (archivo==NULL || archpasajero==NULL)
    {
        printf("Creando archivo");
        fopen("Vuelos.dat","wb");
        exit(1);
    }
    Actualizo(archivo,archpasajero,'Aero1');
    fclose(archivo);

}

void Actualizo