// Archivo principal que maneja el uso de las funciones de la calculadora en C.

// Realizado por Manuel Otarola Madrigal - C05740.

# include <stdio.h>
# include "cabecera.h"

int main(){
    // Mi carne es C05740, entonces los ultimos dos los ultimos dos digitos son:
    int a = 4;
    int b = 0;

    // Se imprimen estos numero en binario para comprobar que esten correctos.
    printf("Los últimos digitos del carne son 4 y 0\n");
    printf("El 4 en binario es: ");
    print_binary(a);
    printf("El 0 en binario es: ");
    print_binary(b);
    printf("\n");

    // Funcion and con estos numeros
    int and = bitwise_and(a, b);
    printf("El resultado de la operacion AND para ambos numeros es: ");
    print_binary(and);

    // Funcion or con estos numeros
    int or = bitwise_or(a, b);
    printf("El resultado de la operacion OR para ambos numeros es: ");
    print_binary(or);

    // Funcion xor con estos numeros
    int xor = bitwise_xor(a, b);
    printf("El resultado de la operacion XOR para ambos numeros es: ");
    print_binary(xor);

    // Funcion not con a
    int not_a = bitwise_not(a);
    printf("El resultado de la operacion NOT para el 4 (0100) es: ");
    print_binary(not_a);

    // Funcion not con b
    int not_b = bitwise_not(b);
    printf("El resultado de la operacion NOT para el 0 (0000) es: ");
    print_binary(not_b);

    return 0;
}
