// El presente programa contiene las funciones de la calculadora, en donde todas las funciones reciben
//números enteros y realizan la operación correspondiente.

// Realizado por Manuel Otárola Madrigal.

#include <stdio.h>
#include <math.h>

// Función que realiza la operación de suma
void suma(int a, int b){
    int resultado_suma = a + b;
    printf("El resultado obtenido de la suma es %d\n", resultado_suma);
}

// Función que realiza la operación de resta
void resta(int a, int b){
    int resultado_resta = a - b;
    printf("El resultado obtenido de la resta es %d\n", resultado_resta);
}

// Función que realiza la operación de multiplicación
void multiplicacion(int a, int b){
    int resultado_multiplicacion = a * b;
    printf("El resultado obtenido de la multiplicación es %d\n", resultado_multiplicacion);
}

// Función que realiza la operacipon de división
// Para obtener el resultado exacto, se debe utilizar los números como float, para obtener decimales
void division(int a, int b){
    float resultado_division = (float) a / b;
    printf("El resultado obtenido de la división es %.3f\n", resultado_division);
}

// Se obtiene la paridad de dos números mediante la siguiente función:
void par(int a, int b){
    if(a % 2 == 0){
        if(b % 2 == 0){
            printf("Ambos numeros ingresados son pares");
        }
        else {
            printf("El numero %d es par y el numero %d es impar\n", a, b);
        }
    }
    if (b % 2 == 0){
        if(b % 2 == 0){
            printf("El numero %d es impar, y el numero %d es par\n", a, b);
        }
        else {
            printf("Ambos numeros son impares");
        }
    }
}

// Función que obtiene el módulo de dos números
void modulo(int a, int b){
    int resultado_modulo = a % b;
    printf("El resultado obtenido de la funcion que obtiene el modulo de dos numeros es %d\n", resultado_modulo);
}

// Función que eleva a la potencia indicada un número
void potencia(int base, int exponente){
    int resultado_potencia = 1;
    for(int i=0; i<exponente; i++){
        resultado_potencia *= base;
    }
    printf("El resultado de la operación de potencia es %d\n", resultado_potencia);
}
