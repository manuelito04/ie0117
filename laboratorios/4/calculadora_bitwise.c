// El presente archivo define las funciones de la calculadora bitwise C.

// Realizado por Manuel Otarola Madrigal - C05740.

#include <stdio.h>

// Funcion and bit a bit
int bitwise_and(int a, int b){
    return a & b;
}

// Funcion or bit a bit
int bitwise_or(int a, int b){
    return a | b;
}

// Funcion xor bit a bit
int bitwise_xor(int a, int b){
    return a ^ b;
}

// Funcion not bit a bit
int bitwise_not(int a){
    return ~a;
}

// Funcion que imprime el numero decimal en binario
void print_binary(int decimal){
    for (int i = 3; i >= 0; i--) {
    
        int digito = decimal >> i;
    
        if (digito & 1)
            printf("1");
        else printf("0");
    }
    printf("\n");
    
}

