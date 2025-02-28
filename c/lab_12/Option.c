#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int QueryOption() {
    int option;
    printf("ENTER CHOICE: ");
    scanf(" %d", &option);
    return option;
}

void ExecuteOption(const int option, node **top) {
    char name[100];
    char type[100];
    char engine[100];

    switch (option) {
        case 0: // Display available options
            DisplayOptions();
            break;

        case 1: // Enter a new value then push new node to stack
            printf("Enter plane name: ");
            scanf(" %s", name);
	    printf("Enter type (figher, transport, ...): ");
            scanf(" %s", type);
            printf("Enter engine type (jet, prop, ...): ");
            scanf(" %s", engine);
            Push(name, type, engine, top);
            break;

        case 2: // Pop top value off stack
            if (*top != NULL) {
                Pop(top, &name, &type, &engine);
                printf("Popped plane = %s, %s, %s\n", name, type, engine);
            } else {
                printf("Stack is empty.\n");
            }
            break;

        case 3: // Peek at top value on stack
	    if (*top != NULL) {
                Peek(*top);
            } else {
                printf("Stack is empty.\n");
            }
            break;

        case 4: // Display the entire stack
            DisplayStack(*top);
            break;

        case 5: // Print stack size
	    int value; // Number of items on the stack
            GetStackSize(*top, &value);
            printf("Stack size is %d\n", value);
            break;

        case 6: // Exit option
            break;

        default:
            printf("Error: incorrect option. Try again.\n");
            break;
    }
}

