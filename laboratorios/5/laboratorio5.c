// El presente programa imprime una pirámide o una pirámide invertida, dependiendo de lo
// que el usuario quiera, además, la impresión puede ser con cualquier caracter y del tamaño de base
// deseado.

// Realizado por Manuel Otárola Madrigal - C05740.

# include <stdio.h>
# include <string.h>

// Funcion que imprime la piramide normal.
void piramide(int base, char caracter){
    for (int i = 1; i <= base; i += 2) {
        for (int j = 0; j < (base - i) / 2; j++) {
            printf(" "); // Centrar la piramide.
        }
        for (int j = 0; j < i; j++) {
            printf("%c", caracter); // Imprime la piramide con el caracter introducido.
        }
        printf("\n");
    }
}

// Funcion que imprime la piramide invertida.
void invertida(int base, char caracter) {
    for (int i = base; i > 0; i -= 2) {
        for (int j = 0; j < (base - i) / 2; j++) {
            printf(" "); // Centrar la piramide.
        }
        for (int j = 0; j < i; j++) {
            printf("%c", caracter); // Imprime la piramide invertida con el caracter introducido.
        }
        printf("\n");
    }
}

// Funcion principal que controla el programa.
int main () {
    char opcion[10];
    int tipo, base;
    char caracter;

    do {
        printf("Seleccione el tipo de piramide que desea construir (1: Normal, 2: Invertida): ");
        scanf("%d", &tipo);
        printf("Seleccione el caracter con el que desea imprimir la piramide: ");
        scanf(" %c", &caracter);
        printf("Seleccione el tamaño de la base (cantidad de caracteres): ");
        scanf("%d", &base);

        // Si la base es par la piramide no queda centrada, por eso se imprime el siguiente mensaje.
        if (base % 2 == 0) {
            printf("La base debe ser un numero impar para que esta esté centrada.\n");
            continue;
        }

        if (tipo == 1) {
            piramide(base, caracter);
        } else if (tipo == 2) {
            invertida(base, caracter);
        } else {
            printf("Opcion no valida\n");
        }

        // Preguntarle al usuario si quiere salir o seguir.
        printf("Escriba 'SALIR' para terminar o cualquie otra cosa para continuar: ");
        scanf("%s", opcion);
    } while (strcmp(opcion, "SALIR") != 0);

    return 0;
}