#include <stdlib.h>
#include "node.h"

void GetStackSize(node *top, int *stack_size) {

  /*
    INPUT: *top (pointer to top of the stack) *stack_size (pointer to interger of stack size)
    OUTPUT: NONE

    Counter the number of nodes in the stack

   */

  if (top == NULL) {
        *stack_size = 0;  // Stack is empty
        return;
    }

    *stack_size = 0;  // Initialize size counter
    node *ptr = top;

    while (ptr != NULL) {
        (*stack_size)++;  // Increment count for each node
        ptr = ptr->next;
    }
}
