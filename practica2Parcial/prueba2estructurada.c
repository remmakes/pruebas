/*Se dispone de un archivo denominado Curso.dat que contiene la información de los inscriptos a un curso de inglés. El archivo aún no está completo ya que la inscripción 
se realiza por partes.
Por cada inscripto se tiene la siguiente información:
    DNI (entero)
    Apellido y Nombres (texto de 20 caracteres máximo)
    Turno (T: Tarde, N: Noche)
    Sexo (F: femenino, M: masculino)
Se desea realizar un programa que cumpla con dos funciones:
a. Agregar nuevos inscriptos (el cupo máximo es de 30 alumnos)
El programa solicitará el ingreso del DNI y lo buscará entre los registros existentes. En caso de que se encuentre dará un mensaje indicando que el alumno ya está inscripto 
y si desea cambiar de turno. En caso de que no lo encuentre dará la opción para inscribirlo al curso.
b. En el momento que ya no quede cupo en el curso se registrará en el archivo Aspirantes.dat los alumnos en lista de espera.
c. Informar el porcentaje de alumnos de sexo femenino y masculino inscriptos al finalizar el programa correspondiente al archivo Curso.dat*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

typedef struct 
{
    int dni;
    char apynmp[21];
    char turno;
    char sexo;
}sCurso;

void Sexo(FILE*);
sCurso Busqueda(FILE*,int);

int main ()
{
    sCurso inscriptos,buscar;
    FILE* archivo;
    int numdni,nuevosi=0;
    char letra;
    archivo= fopen("Curso.dat","r+b");
    if (archivo==NULL)
    {
        puts("Archivo inexistente");
        getchar();
        exit(1);
    }
    printf("Ingrese DNI:");
    scanf("%d",&numdni); 
    buscar=Busqueda(archivo,numdni);
    while (nuevosi<30)
    {
        if (buscar.dni==numdni)
        {
            puts("Alumno ya inscriptro");
            printf("\nDesea cambiar turno?(S-Para Si,N-Para No): ");
            getchar ();
            scanf("%c",&letra);
            letra=toupper(letra);
            if (letra=='S')
            {
                printf("\nElija nuevo turno:");
                scanf("%c",&buscar.turno);
                fseek(archivo,sizeof(inscriptos)*-1,SEEK_CUR);
                fwrite(&inscriptos,sizeof(sCurso),1,archivo);
                fflush(archivo);
            }
            printf("Ingrese DNI:");
            scanf("%d",&numdni); 
            buscar=Busqueda(archivo,numdni);
        }
        if (buscar.dni==-1)
        {   
            
            printf("Desea inscribirlo? (S-Para Si,N-Para No):");
            scanf("%c",&letra);
            letra=toupper(letra);
            if (letra=='S')
            {
                inscriptos.dni=numdni;
                printf("Ingrese apellido y nombre:");
                fflush(stdin);
                gets(inscriptos.apynmp);
                printf("\nIngrese turno: ");
                scanf("%c",&inscriptos.turno);
                printf("\nIngrese sexo: ");
                scanf("%c",&inscriptos.sexo);
                fwrite(&inscriptos,sizeof(sCurso),1,archivo);
                fflush(archivo);
                nuevosi++;
            }
        printf("Ingrese DNI:");
        scanf("%d",&numdni); 
        buscar=Busqueda(archivo,numdni);
        }              
    }   
    //b. En el momento que ya no quede cupo en el curso se registrará en el archivo Aspirantes.dat los alumnos en lista de espera.
    FILE *arch2;
    if (nuevosi>30)
    {
        arch2=fopen("Aspirantes.dat","wb");
        if (arch2==NULL)
        {
            printf("\nError al crear al archivo");
            exit(1);
        }
        printf("\nIngrese numero de dni: ");
        scanf("%d",&inscriptos.dni);
        
        while (inscriptos.dni>0)
        {
            getchar();
            printf("Ingrese apellido y nombre: ");
            gets(inscriptos.apynmp);
            printf("\nIngrese turno: ");
            scanf("%c",&inscriptos.turno);
            getchar();
            printf("\nIngrese sexo: ");
            scanf("%c",&inscriptos.sexo);
            fwrite(&inscriptos,sizeof(sCurso),1,arch2);

            printf("\nIngrese numero de dni: ");
            scanf("%d",&inscriptos.dni);
        }
    }
    Sexo(archivo);
    fclose(archivo);
    fclose(arch2);
    //c. Informar el porcentaje de alumnos de sexo femenino y masculino inscriptos al finalizar el programa correspondiente al archivo Curso.dat*/
    
    return 0;
}

sCurso Busqueda(FILE* archivo,int nb)
{
    sCurso registro;
    rewind(archivo);
    int encontrado=0;
    fread(&registro,sizeof(sCurso),1,archivo);
    while (!feof(archivo))
    {
        if (nb==registro.dni)
        {
            encontrado=1;
        }
        else
            fread(&registro,sizeof(sCurso),1,archivo);
    }
    if (encontrado==0)
    {
        registro.dni=-1;
    }
    return registro;
};

void Sexo(FILE* archivo)
{
    sCurso recorrer;
    rewind(archivo);
    int masculino=0,femenino=0;
    fread(&recorrer,sizeof(sCurso),1,archivo);
    while (!feof(archivo))
    {
        if(recorrer.sexo=='F')
        {
            femenino++;
        }
        else if (recorrer.sexo=='M')
        {
            masculino++;
        }
        fread(&recorrer,sizeof(sCurso),1,archivo);
    }
    printf("\nLa porcentaje total de alumnos MASCULINOS es: %.2f %",((masculino+femenino)/masculino)*100.00);
    printf("\nLa porcentaje total de alumnos FEMENINOS es: %.2f %",((masculino+femenino)/femenino)*100.00);
}