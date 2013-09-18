/****
	Prefix to Infix Notation Conversion
	Algorithm design and C code implementation by Raven G. Duran BSIT 2R1
	Mindanao University of Science and Technology (MUST)
****/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // For "Is alpha numeric" function

#define MAX_TERM_LENGTH 100
#define MAX_TERMS 50


// For the Operator Stack
struct oprStack{
    char opr;
    struct oprStack *next;
}*head = NULL;

char popOpr();
void pushOpr(char opr);
void getInfix();

int main(){
    char again = 'y';
    
    while(again == 'y'){
        getInfix();
        printf("\nConvert Another? (y)es or (n)o\n");
        again = tolower(getch());
    }
    
    return 0;
}

char popOpr(){
    struct oprStack *n;
    char opr;
    if (head == NULL){
        printf("Stack Underflow!");
        getch();
        exit(-1);
    } else {
        opr = head->opr;
        n = head;
        head = head->next;
        free(n);
        return opr;
    }
}

void pushOpr(char opr){
    struct oprStack *n = (struct oprStack*)malloc(sizeof(struct oprStack));
    n->opr = opr;
    if (head == NULL){
        head = n;
        head->next = NULL;
    } else {
        n->next = head;
        head = n;
    }
}

 // For the terms
int currentTerm = 0;
int termIndex = 0;
char terms[MAX_TERMS][MAX_TERM_LENGTH]; 

void getInfix(){
    char prefix[100], char final[500], char lastPopped;
    strcpy(final," ");
    int i,j; // J is used for iterating when adding parenthesis
    
    printf("Prefix Expression: ");
    gets(prefix);
    
    for (i = 0; i < strlen(prefix);i++){
        if (!isalnum(prefix[i]) && !isalnum(prefix[i-1])){
            pushOpr(prefix[i]);
        } else if (isalnum(prefix[i]) && !isalnum(prefix[i-1])){
            terms[currentTerm][termIndex++] = prefix[i];
        } else if (isalnum(prefix[i]) && isalnum(prefix[i-1])){
            terms[currentTerm][termIndex++] = (lastPopped = popOpr());
            terms[currentTerm][termIndex++] = prefix[i];
            // Add Parenthesis
              for (j = strlen(terms[currentTerm])-1; j >= 0; j--){
                  terms[currentTerm][j+1] = terms[currentTerm][j];
              }
              terms[currentTerm][0]='(';
              terms[currentTerm][strlen(terms[currentTerm])] = ')';
              termIndex = strlen(terms[currentTerm]);
        } else if (!isalnum(prefix[i]) && isalnum(prefix[i-1])){
            terms[currentTerm][strlen(terms[currentTerm])] = popOpr();
            pushOpr(prefix[i]);
            currentTerm++;
            termIndex = 0;
        }
    }
    for (i = 0; i <= currentTerm;i++){
        strcat(final,terms[i]);
    }
    final[strlen(final)] = '\0';
    printf("Infix Equivalent: %s\n",final);
    
    // Clear and reset everything
    while (head != NULL)free(head);
    currentTerm = 0;
    termIndex = 0;
    for (i = 0; i < MAX_TERMS; i++){ for (j = 0; j < MAX_TERM_LENGTH; j++)terms[i][j] = '\0';}
}