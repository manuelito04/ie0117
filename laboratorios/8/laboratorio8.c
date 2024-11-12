// El presente programa desarrolla una solucion para el laboratorio 8 asignado.

// Realizado por Manuel Alejandro Otárola Madrigal - C05740.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definicion del struct datos_persona
typedef struct {
    char nombre[50];
    char apellido[50];
    int telefono;
    char carnet[8];
    char enfasis[50];
} datos_persona;

// Funcion para validar que el nombre o apellido contenga solo letras.
int validar_nombre_apellido(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) { // Verifica que tenga solo caracteres alfa.
            printf("El nombre o apellido solo puede contener letras.\n");
            return 0;
        }
    }
    return 1;
}

// Funcion para validar que el telefono tenga exactamente 8 digitos.
int validar_telefono(int telefono) {
    if (telefono < 10000000 || telefono > 99999999) {
        printf("El teléfono debe tener exactamente 8 dígitos.\n");
        return 0;
    }
    return 1;
}

// Funcion para validar que el carnet solo contenga caracteres alfanumericos.
int validar_carnet(const char *carnet) {
    for (int i = 0; carnet[i] != '\0'; i++) {
        if (!isalnum(carnet[i])) { // Verifica que solo tenga caracteres numericos.
            printf("El carnet solo puede contener caracteres alfanumericos.\n");
            return 0;
        }
    }
    return 1;
}

// Establecer las funciones.
void set_struct(datos_persona *persona);
void print_struct(const datos_persona *persona);
int validar_nombre_apellido(const char *str);
int validar_telefono(int telefono);
int validar_carnet(const char *carnet);

// Funcion para imprimir los datos del struct.
void print_struct(const datos_persona *persona) {
    printf("\nNombre: %s\n", persona->nombre);
    printf("Apellido: %s\n", persona->apellido);
    printf("Telefono: %d\n", persona->telefono);
    printf("Carnet: %s\n", persona->carnet);
    printf("Enfasis: %s\n", persona->enfasis);
}

// Funcion para llenar el struct.
void set_struct(datos_persona *persona) {
    // Leer el nombre.
    do {
        printf("Nombre (solo letras): ");
        scanf("%s", persona->nombre);
    } while (!validar_nombre_apellido(persona->nombre));
    
    // Leer el apellido.
    do {
        printf("Apellido (solo letras): ");
        scanf("%s", persona->apellido);
    } while (!validar_nombre_apellido(persona->apellido));

    // Leer el telefono.
    do {
        printf("Telefono (exactamente 8 digitos): ");
        scanf("%d", &persona->telefono);
    } while (!validar_telefono(persona->telefono));

    // Leer el carnet.
    do {
        printf("Carnet (solo alfanumerico): ");
        scanf("%s", persona->carnet);
    } while (!validar_carnet(persona->carnet));

    // Leer el enfasis.
    printf("Enfasis: ");
    scanf("%s", persona->enfasis);
}

int main() {
    int n, opcion, encontrado;
    char carnet_buscado[20];
    datos_persona *personas = NULL;

    // Menu de opciones.
    do {
        printf("\nMenu de opciones:\n");
        printf("1. Agregar persona\n");
        printf("2. Buscar persona\n");
        printf("3. Imprimir todas las personas\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:  // Agregar persona.

                // Pedir al usuario el numero de personas.
                printf("Ingrese el numero de personas que desea guardar: ");
                scanf("%d", &n);

                // Reservar memoria dinamica para el arreglo de estructuras.
                personas = (datos_persona*)malloc(n * sizeof(datos_persona));
                if (personas == NULL) {
                printf("Error al reservar memoria.\n");
                return 1;
                }

                for (int i = 0; i < n; i++) {
                    printf("\nIngrese los datos de la persona %d:\n", i + 1);
                    set_struct(&personas[i]);
                }
                break;

            case 2:  // Buscar persona.
                printf("\nIngrese el carnet de la persona a buscar: ");
                scanf("%s", carnet_buscado);
                encontrado = 0;

                for (int i = 0; i < n; i++) {
                    if (strcmp(personas[i].carnet, carnet_buscado) == 0) {
                        printf("\nPersona encontrada:\n");
                        print_struct(&personas[i]);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Persona no encontrada.\n");
                }
                break;

            case 3:  // Imprimir todas las personas.
                printf("\nLista de todas las personas:\n");
                for (int i = 0; i < n; i++) {
                    print_struct(&personas[i]);
                }
                break;

            case 4:  // Salir del programa.
                printf("Muchas gracias por utilizar el programa.\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }

    } while (opcion != 4);

    // Liberar la memoria antes de terminar.
    free(personas);
    return 0;
}
