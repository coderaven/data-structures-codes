#include <stdio.h>
#include <malloc.h>

struct node {
    char letter;
    struct node *next;
} *head;

void push(char letter);

int main(){
    struct node *iterator;
    char str[100];
    int i;
    
    printf("Enter a string: ");
    gets(str);
    
    // Push every letter to the stack
    for (i = 0; i < strlen(str); i++){
        push(str[i]);
    }
    
    // Print every letter from stack
    printf("Output from stack: ");
    for (iterator = head; iterator != NULL; iterator = iterator->next) printf("%c",iterator->letter);
    
    getch();
    return 0;
}

void push(char letter){
     struct node *newNode = (struct node*)malloc(sizeof(struct node));
     newNode->letter = letter; 
     if (head == NULL){
        head = newNode;
        head->next = NULL;
     } else {
        newNode->next = head;
        head = newNode;
     }
}