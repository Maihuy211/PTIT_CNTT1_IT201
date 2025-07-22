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
int main(){
    
    int value;
    printf("nhap mot so: ");
    scanf("%d",&value);

    Node* root = createNode(value);
    printf("\ndata: %d",root->data);
    if(root->left == NULL){
        printf("\nleft->NULL");
    }
    if(root->right == NULL){
        printf("\nright->NULL");
    }
    return 0;
}
