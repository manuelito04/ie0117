// El presente programa busca que el usuario ingrese la información de tres animales distintos
// y que luego se imprima en pantalla esta informacion, pero haciendo uso de structs.

// Realizado por Manuel Alejandro Otarola Madrigal - C05740.

#include <stdio.h>

// Se implementa el struct con la info del animal.
struct animal {
    char nombre[50]; // Del tipo char y con extension maxima de 50 caracteres.
    int edad; // Dl tipo int.
    char especie[50]; // Del tipo char con extension maxima de 50 caracteres.
};

// Se implementa la funcion principal del programa que lo controla.
int main() {
    struct animal animales[3]; // Se llama al struct y se van a ingresar la info de tres animales.

    // Se le pide los datos al usuario de tres animales.
    for (int i = 0; i < 3; i++) {
        printf("Ingrese el nombre del animal %d: ", i + 1);
        fgets(animales[i].nombre, 50, stdin);

        printf("Ingrese la edad del animal %d: ", i + 1);
        scanf("%d", &animales[i].edad);
        getchar(); // Se limpia la entrada.

        printf("Ingrese la especie del animal %d: ", i + 1);
        fgets(animales[i].especie, 50, stdin);
    }

    // Se imprimen los datos de los animales.
    for (int i = 0; i < 3; i++) {
        printf("\nAnimal %d:\n", i + 1);
        printf("Nombre: %s", animales[i].nombre);
        printf("Edad: %d\n", animales[i].edad);
        printf("Especie: %s\n", animales[i].especie);
    }

    return 0;

}