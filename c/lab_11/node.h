# ifndef __NODE_H__
# define __NODE_H__

typedef struct node node;
struct node {
    int position ;
    char value ;
    node* next;
};

// Functions associated with struct node
int GetNumberOfNodes ();
void GenerateList (node ** head , const int num);
void Print ( const int forward , const node* head);
void PrintList ( const node* head);
void ReversePrintList ( const node* head);
char GetKey ();
void SearchList ( const node* head , const char key);
void DeleteList (node ** head);

# endif
