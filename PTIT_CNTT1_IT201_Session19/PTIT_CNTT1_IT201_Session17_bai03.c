#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
}Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void portorder(Node* root){
    if(root != NULL){
        portorder(root->left);
        portorder(root->right);
        printf("%d\n", root->data);
    }
}

int main(){
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("\nPortorder (LRN) \n");
    portorder(root);

    return 0;
}
