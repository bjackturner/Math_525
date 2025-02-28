#ifndef NODE_H
#define NODE_H

#include <string.h>
#include <stdio.h>

typedef struct node {
    int position;
    char name[100];
    char type[100];
    char engine[100];
    struct node* next;
} node;

// Functions associated with struct node
void DisplayOptions();
void Push(const char* name, const char* type, const char* engine, node **top);


int  GetNumberOfNodes(void);
void GenerateList(node** head, int num);
void Print(int forward, const node* head);
void PrintList(const node* head);
void ReversePrintList(const node* head);
int  GetKey(void);
void SearchList(const node* head, int key);
void DeleteList(node** head);

#endif // NODE_H
