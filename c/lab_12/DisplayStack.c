#include <stdio.h>
#include "node.h"

void DisplayStack(node *top) {

  /*
    INPUT:  node *top (pointer to the top node of the stack)
    OUTPUT: NONE

    Displays every item on the stack, and the current and next address
  */
  
  if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("-------------------------------------------------------------------\n");
    printf("| Pos  |  Name  |  Type  |  Engine  |    Address     |    Next    |\n");
    printf("-------------------------------------------------------------------\n");

    PrintNode(top);

    printf("-------------------------------------------------------------------\n");
}

void PrintNode(node *top) {

  /*
    INPUT:  node *top (pointer to top node on the stack)
    OUTPUT: Recursive call to print each item on the stack

    prints out the current node number, all of the values on the stack, and the memory address of the current and next node
  */

  if (top == NULL) return;  // Base case to avoid null dereference

    // Ensure the strings are valid before printing
    printf("| %3i  | %s | %s  | %s  | %15p | %15p |\n",
           top->position,
           (top->name[0] != '\0') ? top->name : "NULL",    // Avoid printing uninitialized strings
           (top->type[0] != '\0') ? top->type : "NULL",
           (top->engine[0] != '\0') ? top->engine : "NULL",
           (void *)top,
           (void *)top->next);

    PrintNode(top->next);  // Recursively print next node
}
