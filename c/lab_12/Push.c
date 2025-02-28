#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void Push(const char* name, const char* type, const char* engine, node **top) {
    // Allocate memory for new node
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Copy string values into the new node
    strncpy(new_node->name, name, sizeof(new_node->name) - 1);
    strncpy(new_node->type, type, sizeof(new_node->type) - 1);
    strncpy(new_node->engine, engine, sizeof(new_node->engine) - 1);
    
    // Ensure strings are null-terminated
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->type[sizeof(new_node->type) - 1] = '\0';
    new_node->engine[sizeof(new_node->engine) - 1] = '\0';

    // Set new node's position
    new_node->position = (*top == NULL) ? 1 : (*top)->position + 1;

    // Link the new node to the stack
    new_node->next = *top;
    *top = new_node;
}
