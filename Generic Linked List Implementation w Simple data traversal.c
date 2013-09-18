/****
     Generic Linked List Implementation w/ Simple data traversal example
     by Raven G. Duran                  BSIT 2R1 :)
***/

#include <stdio.h>
#include <malloc.h>

struct node {                         // This is a generic example of a node.
       int data;                      // You can add more properties if you want :)
       struct node *next;
};

int main(){
    struct node *head = NULL, *tail, *curr;      // The head is used as a pointer to the first node, 
    int i,n;                                     // we set it to NULL for flag purposes later when 
                                                 // creating the first node. tail is used as a pointer 
    printf("Number of nodes: ");                 // to the last created node and curr is used to point 
    scanf("%d",&n);                              // to any node and basically used for traversing.
    
    for (i = 1; i <= n; i++){
        curr = (struct node*)malloc(sizeof(struct node));// Naa ra ang malloc that you wanted to see oh :)
                                                        // This basically just allocates memory with a 
        printf("Enter value for node %d: ",i);          // size equal to the node structure.
        scanf("%d",&curr->data);
        
        if (head == NULL) head = curr;
        else tail->next = curr;
        
        tail = curr;
        tail->next = NULL;
    }
    
    printf("\n----- Data list -----\n");
    for (curr = head; curr != NULL; curr = curr->next) printf("%d\n",curr->data);  
                                                       // Set the curr to the head and end if it is NULL
    getch();          
    return 0;
}



// Good luck :)