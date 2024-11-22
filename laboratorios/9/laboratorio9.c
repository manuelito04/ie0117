// El presente programa permite al usuario interactuar con una cola implementada
// con listas enlazadas simples. 

// Realizado por Manuel Alejandro Otarola Madrigal - C05740.

#include <stdio.h>
#include <stdlib.h>

// Se define el nodo para la lista enlazada simple.
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente; // Se redirige el puntero.
} Nodo;

// Se define la estructura de la cola.
typedef struct Cola {
    Nodo* frente;
    Nodo* final; // Se redirige el puntero al inicio y final de la cola para llenara.
} Cola;

// Se crea una cola vacia para cuando se empieza con la interaccion con el usuario.
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->frente = NULL;
    cola->final = NULL;
    return cola;
}

// Se verifica que la cola este vacia.
int colaVacia(Cola* cola) {
    return cola->frente == NULL;
}

// Funcion para agregar un elemento a la cola (enqueue).
void agregarElemento(Cola* cola, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    if (colaVacia(cola)) {
        cola->frente = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
    }
    cola->final = nuevoNodo;
    printf("Elemento %d agregado a la cola.\n", valor);
}

// Funcion para eliminar un elemento de la cola (dequeue).
void quitarElemento(Cola* cola) {
    if (colaVacia(cola)) {
        printf("La cola esta vacia, no se puede eliminar un elemento.\n");
        return;
    }
    Nodo* temp = cola->frente;
    cola->frente = cola->frente->siguiente;
    if (cola->frente == NULL) { // Verifica si la cola quedo vacia.
        cola->final = NULL;
    }
    printf("Elemento %d eliminado de la cola.\n", temp->dato);
    free(temp);
}

// Funcion para imprimir los elementos de la cola.
void imprimirCola(Cola* cola) {
    if (colaVacia(cola)) {
        printf("La cola esta vacia.\n");
        return;
    }
    Nodo* actual = cola->frente;
    printf("Elementos en la cola: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Funcion que controla el programa.
int main() {
    Cola* cola = crearCola();
    int opcion, valor;

    do {
        printf("\nMenú de opciones:\n");
        printf("1. Imprimir la cola\n");
        printf("2. Agregar un elemento (enqueue)\n");
        printf("3. Eliminar un elemento (dequeue)\n");
        printf("4. SALIR\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimirCola(cola);
                break;
            case 2:
                printf("Ingrese el valor a agregar: ");
                scanf("%d", &valor);
                agregarElemento(cola, valor);
                break;
            case 3:
                quitarElemento(cola);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    // Liberar la memoria utilizada por la cola.
    while (!colaVacia(cola)) {
        quitarElemento(cola);
    }
    free(cola);

    return 0;
}