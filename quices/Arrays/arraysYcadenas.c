// El presente es un programa al cual le ingresa una palabra de maximo 20 caracteres,
// la imprime, calcula su longitud y la imprime de manera inversa.

// Realizado por Manuel Otarola Madrigal - C05740.

#include <stdio.h>
#include <string.h>

int main(){
    // Array de 20 caracteres para establecer el maximo.
    char palabra[20];

    // Ingresar una palabra:
    printf("Ingrese una palabra de maximo 20 letras: ");

    //Leer hasta el máximo de 20 caracteres:
    scanf("%20s", palabra);

    // Imprimir palabra ingresada:
    printf("La palabra ingresada es: %s\n", palabra);

    // Longitud de la palabra:
    int longitud = strlen(palabra);
    printf("La longitud de la palabra es: %d\n", longitud);

    // Invertir palabra ingresada:
    printf("La palabra tras invertirla es: ");
    for (int i = longitud - 1; i>=0; i--){
        putchar(palabra[i]);
    }
    printf("\n");

    return 0;
}
