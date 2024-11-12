#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct node {
    int val;
    struct node *next;
} node_t;

// Function to print the list
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

// Function to append a node to the end of the list
void append(node_t *head, int val) {
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

// Function to prepend a node to the beginning of the list
node_t *prepend(node_t *head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

// Function to delete the first node
node_t *delete_first(node_t *head) {
    if (head == NULL) return NULL;
    node_t *new_head = head->next;
    free(head);
    return new_head;
}

// Function to delete a node by value
void delete_by_value(node_t **head, int val) {
        if (*head == NULL) {
        return;  // Lista vacía, no hacer nada
    }

    node_t *current = *head;
    node_t *previous = NULL;

    // Si el nodo a eliminar es el primero
    if (current != NULL && current->val == val) {
        *head = current->next;  // Mover el head al siguiente nodo
        free(current);  // Liberar la memoria del nodo
        return;
    }

    // Buscar el nodo a eliminar en el resto de la lista
    while (current != NULL && current->val != val) {
        previous = current;
        current = current->next;
    }

    // Encontrar el nodo a eliminar
    if (current != NULL) {
        previous->next = current->next;  // Saltar el nodo actual
        free(current);  // Liberar la memoria del nodo eliminado
    }
}

int main() {
    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = NULL;

    append(head, 2);
    append(head, 3);
    print_list(head);

    head = prepend(head, 0);
    print_list(head);

    head = delete_first(head);
    print_list(head);

    delete_by_value(&head, 2);
    print_list(head);

    return 0;
}