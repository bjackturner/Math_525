#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void SearchList(const node* head, const char key) {
    if (head == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    if (head->value == key) {
        printf("Key found at Position: %i\n", head->position);
        return; // Stop recursion if found
    }

    SearchList(head->next, key);
}
