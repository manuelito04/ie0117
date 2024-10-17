// El presente programa es capaz de dos numeros a traves de la linea de comandos y calcula el maximo
// comun divisor de ambos mediante la formula de Euclides.

// Realizado por Manuel Otarola Madrigal - C05740.

# include <stdio.h>
# include <stdlib.h>

// Se implementa la funcion que calcula el maximo comun divisor de los numeros que se ingresen.
int mcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mcd(b, a % b);
}
// Se implementa la funcion principal que maneja el programa.
int main(int argc, char *argv[]) {
    // Se implementan los mensajes de error.

    // Error por si se ingresan mas de dos argumentos.
    if (argc != 3) {
        printf("Ingrese solo dos numeros enteros.\n");
        return 1;
    }

    // Convertir los numeros ingresados de argumentos a enteros.
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    // Error en caso de que ambos numeros sean cero.
    if (a == 0 && b == 0) {
        printf("Ingrese al menos un numero diferente de 0.\n");
        return 1;
    }

    // Error en caso de que algun numero sea menor a 0.
    if (a < 0 || b < 0) {
        printf("Ingrese un numero entero positivo.\n");
        return 1;
    }

    // Llamar a la funcion que calcla el maximo comun divisor.
    int resultado = mcd(a, b);

    // Imprimir el resultado.
    printf("El Maximo Comun Divisor de %d y %d es %d\n", a, b, resultado);

    return 0;
    

}