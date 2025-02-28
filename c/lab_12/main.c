#include <stdlib.h>
#include "node.h"

// Function prototypes (if they are not in node.h)
void ExecuteOption(int option, node** top);
int QueryOption(void);
void DeleteStack(node** top);

int main() {
    node* top = NULL;
    int option = 0;

    while (option != 6) {
        ExecuteOption(option, &top);
        option = QueryOption();
    }

    DeleteStack(&top);
    return 0;
}
