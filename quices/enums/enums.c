// El presente programa crea un enum de niveles de log e implementa una funcion para imprimir mensajes 
// segun el nivel.

// Realizado por Manuel Alejandro Otárola Madrigal - C05740.

#include <stdio.h>

// Se define el enum para los niveles de log.
enum LogNiveles {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

// Funcion para imprimir mensajes segun el nivel de log.
void logMensaje(enum LogNiveles nivel, const char *mensaje) {
    switch (nivel) {
        case DEBUG:
            printf("[DEBUG]: %s\n", mensaje);
            break;

        case INFO:
            printf("[INFO]: %s\n", mensaje);
            break;

        case WARN:
            printf("[WARN]: %s\n", mensaje);
            break;
        case ERROR:
            printf("[ERROR]: %s\n", mensaje);
            break;
    }
}

// Se implementa el controlador del sistema encargado de mostrar los mensajes segun el mensaje de log.
int main() {
    logMensaje(INFO, "Inicio del programa");
    logMensaje(DEBUG, "Variable x inicializada a 0");
    logMensaje(WARN, "La conexion es inestable");
    logMensaje(ERROR, "Archivo no encontrado");

    return 0;
}
