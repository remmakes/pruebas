/*3.6 Realizar el juego del ahorcado. Primero se debe ingresar la palabra a adivinar de hasta 10 caracteres. Luego
se muestra por cada letra un guion bajo para que el jugador sepa la cantidad de letras a adivinar. Se irá
ingresando una a una las letras y si estas se encuentran en la palabra las deberá ir mostrando en el lugar
correspondiente. Por cada letra que no se encuentre en la palabra perderá una vida. El jugador dispondrá de
5 vidas para intentar ganar el juego.
Complemento:
• Ir completando el dibujo del muñeco del ahorcado cada vez que se comete un error.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mostrarahorcado(int);

int main()
{
    char palabra[12], letra;
    int largo, vidas = 6;
    puts("ingrese la palabra a adivinar");
    fgets(palabra, 12, stdin);
    largo = strlen(palabra);
    if (palabra[largo - 1] == '\n')
        palabra[largo - 1] = '\0';
    system("cls");
    char adivina[largo];
    ;
    for (int i = 0; i < largo - 1; i++)
    {
        adivina[i] = '_';
        printf("%c", adivina[i]);
    }

    while (vidas != 0 && strcmpi(palabra, adivina) != 0)
    {

        printf("\nIngrese una letra: ");
        scanf(" %c", &letra);
        int acierto = 0;
        for (int i = 0; i < largo; i++)
        {
            if (palabra[i] == letra)
            {
                adivina[i] = letra;
                acierto = 1;
            }
        }

        for (int j = 0; j < largo; j++)
        {
            printf("%c ", adivina[j]);
        }
        printf("\n");

        if (acierto == 0)
        {
            vidas--;
            printf("Te quedan %d intentos\n", vidas);
            mostrarahorcado(vidas);
        }
    }
    return 0;
}

void mostrarahorcado(int vidas)
{
    switch (vidas)
    {
    case 5:
        printf("  O\n");
        break;
    case 4:
        printf("  O\n");
        printf("  <\n");
        break;
    case 3:
        printf("  O\n");
        printf(" <|\n");
        break;
    case 2:
        printf("  O\n");
        printf(" <|>\n");
        break;
    case 1:
        printf("  O\n");
        printf(" <|>\n");
        printf(" _|\n");
        break;
    case 0:
        printf("  O\n");
        printf(" <|>\n");
        printf(" _|_\n");
        break;
    }
}