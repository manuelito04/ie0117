// El presente programa pide al usuario una fecha en el formato dd-mm-aaaa e imprime
// esta fecha en un formato legible.

// Realizado por Manuel Alejandro Otárola Madrigal - C05740.

// Librerias utiles para implementar el programa.
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// Se implementa una funcion capaz de obtener el nombre en prosa del mes ingresado.
const char* nombreMes(int mes) {
    const char* meses[] = {"", "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    if (mes >= 1 && mes <= 12) {
        return meses[mes];
    }
    return "";
}

// Funcion principal del programa.
int main() {
    char fecha[11]; // Tamaño del formato de la fecha a ingresar
    int dia;
    int mes;
    int ano; // Definir las variables del dia, mes y año.

    // Pedirle al usuario la fecha con el formato indicado.
    printf("Ingrese la fecha en el formato dd-mm-aaaa: ");
    fgets(fecha, sizeof(fecha), stdin);

    // Mostrar que el formato no es el valido si se ingresan mas parametros que los deseados.
    if (sscanf(fecha, "%d-%d-%d", &dia, &mes, &ano) !=3) {
        printf("El formato de la fecha introducido no es valido\n");
        return 1; // Retorna 1 para terminar el programa en este momento
    }

    // Mostrar que el formato no es valido si se ingresa un dia mayor a 31 o mes mayor a 12.
    if(dia < 1 || dia > 31 || mes < 1 || mes > 12) {
        printf("La fecha introducida es invalida; el dia debe estar entre 1 y 31, y el mes entre 1 y 12.\n");
        return 1; // Retorna 1 para terminar el programa en este momento.
    }

    // Convertir la fecha a un formato legible.
    printf("La fecha es: %d de %s de %d\n", dia, nombreMes(mes), ano);
    return 0; // El programa finaliza con exito.
}