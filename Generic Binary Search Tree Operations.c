#include <stdio.h>
/******* Generic Binary Search Tree Operations                    *******/
/****** Implemented in C and coded by Raven G. Duran BSIT - 2R1   *******/

struct node {
       int value;
       struct node *left;
       struct node *right;
};

// Functions for creating a BST structure
struct node* newNode(int value);  // Create a single node
struct node* insertN(struct node *root,int value); // Insert the node properly to BST

// Common Operations for BST structues
int searchNode(struct node *root, int value);  // Return 1 if found else 0 if not found
int findMin(struct node *root);  // Returns the smallest number in the tree
int findMax(struct node *root);  // Returns the biggest number in the tree

void preOrderTraverse(struct node *root);
void inOrderTraverse(struct node *root);
void postOrderTraverse(struct node *root);

int main(){
    int i,toLook,nodes;
    int numbers[100];
    struct node *root = NULL;
    
    // Creatiion
    printf("\n----- Creating the BST structure -----\n");
    printf("Number of BST nodes: ");
    scanf("%d",&nodes);
    
    for (i = 0; i < nodes; i++){
        printf("Node %d: ",i+1);
        scanf("%d",&numbers[i]);
        
        root = insertN(root,numbers[i]);
    }
    
    // Search for a value in the tree
    printf("\n----- Searching -----\n");
    printf("Lookup: ");
    scanf("%d",&toLook);
    
    if (searchNode(root,toLook)) printf("Found!\n");
    else printf("Not found!\n");
    
    // Get the minimum and maximum values
    printf("\n----- Finding Max and Min -----\n");
    int min = findMin(root);
    int max = findMax(root);
    printf("Min: %d\nMax: %d\n",min,max);
    
    // Traversals
    printf("\n----- PreOrder Traverse -----\n");
    preOrderTraverse(root);
    
    printf("\n----- InOrder Traverse -----\n"); 
    inOrderTraverse(root); // InOrder Traversal Always gives numbers in ascending sorted manner
    
    printf("\n----- PostOrder Traverse -----\n");
    postOrderTraverse(root);
    
    getch(); // Delete this line if you'll use netbeans or visual C to compile
    return 0;
}

struct node* newNode(int value){
       struct node *root = (struct node*)malloc(sizeof(struct node));
       root->value = value;
       root->left = NULL;
       root->right = NULL;
}

struct node* insertN(struct node *root,int value){
       if (root == NULL){
          return newNode(value);
       } else {
         if (value < root->value) root->left =  insertN(root->left,value);
         else root->right = insertN(root->right,value);
         
         return root;
       }
}

int searchNode(struct node *root, int value){
    if (root == NULL) return 0;
    else {
         if (root->value == value) return 1;
         else {
              if (value < root->value) return searchNode(root->left,value);
              else return searchNode(root->right,value);
         }
    }
}

int findMin(struct node *root){
    while(root != NULL){
        if (root->left == NULL) return root->value;
        else root = root->left;
    }
}

int findMax(struct node *root){
   while(root != NULL){
        if (root->right == NULL) return root->value;
        else root = root->right;
    }
}

void preOrderTraverse(struct node *root){
     if (root != NULL){
        printf("%d\n",root->value);
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
     }
}

void inOrderTraverse(struct node *root){
     if (root != NULL){
        inOrderTraverse(root->left);
        printf("%d\n",root->value);
        inOrderTraverse(root->right);
     }
}

void postOrderTraverse(struct node *root){
     if (root != NULL){
        postOrderTraverse(root->left);
        postOrderTraverse(root->right);
        printf("%d\n",root->value);
     }
}