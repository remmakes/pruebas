#include <stdio.h>

int main() {
    char texto[10];

    printf("Ingresa un texto (max 9 caracteres): ");
    scanf("%9s", texto);

    printf("El texto ingresado es: %s\n", texto);

    return 0;
}