#include <stdio.h>

#include "node.h"

int GetNumberOfNodes() {
    int num;
    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    // Ensure the number is non-negative
    while (num < 0) {
        printf("Number of nodes cannot be negative. Please enter again: ");
        scanf("%d", &num);
    }

    return num;
}

void GenerateList(node **head, const int num_nodes) {  
    node* temp;  
    srand(time(NULL));  

    for (int i = 0; i < num_nodes; i++) {  
        temp = (node *)malloc(sizeof(node));  
        temp->value = rand() % num_nodes;  
        temp->position = 0;  
        printf("%4i", temp->value);  

        if (*head == NULL) {  
            *head = temp;  
            (*head)->next = NULL;  
        } else {  
            temp->next = *head;  
            *head = temp;  
        }  
    }  

    printf ("\n");
    node* ptr = *head; int pos = 1;

    while (ptr != NULL){
        ptr -> position = pos;
        pos = pos +1;
        ptr = ptr ->next;
    }
}