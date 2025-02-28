#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void DeleteStack(node **top) {
  /*
  INPUT: node **top (pointer to the pointer to the top of the stack)

  Deletes the entire stack and displays goodby message
  */

  if (top == NULL || *top == NULL) {
        printf("\nStack is already empty.\n\n");
        return;
    }

    node *temp;
    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }

    printf("\nGoodbye!\n\n");
}
