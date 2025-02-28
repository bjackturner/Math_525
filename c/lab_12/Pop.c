#include "node.h"
#include <string.h>  // for strcpy

void Pop(node **top, char *name, char *type, char *engine) {
  /*
    INPUT: **top (pointer to pointer to top of stack), name, type, engine (pointer to string

    prints the top of the stack and removes it from the stack

   */

  if (*top == NULL) {
        return;  // Stack is empty, nothing to pop
    }

    node *temp = *top;  // Store current top node

    // Copy the values from the node into the provided variables
    strcpy(name, temp->name);  // Copy name to the provided char array
    strcpy(type, temp->type);  // Copy type to the provided char array
    strcpy(engine, temp->engine);  // Copy engine to the provided char array

    *top = temp->next;  // Move top to the next node
    free(temp);  // Free the old top node

    // Update positions of remaining nodes
    node *ptr = *top;
    while (ptr != NULL) {
        ptr->position -= 1;
        ptr = ptr->next;
    }
}
