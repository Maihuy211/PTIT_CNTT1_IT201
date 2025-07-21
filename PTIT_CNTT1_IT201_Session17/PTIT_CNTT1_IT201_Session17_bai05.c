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

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}
int searchValue(Node* root , int findValue){
    if(root == NULL){
        return 0;
    }
    if(root->data==findValue){
        return 1;
    }
    if(searchValue(root->left,findValue)){
        return 1;
    }
    if(searchValue(root->right,findValue)){
        return 1;
    }
    return 0;
}
int main(){
   Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("\nInorder (LNR) \n");
    inorder(root);
    int findValue;
    printf("nhap so can tim: ");
    scanf("%d",& findValue);
    int check = searchValue(root,findValue);
    if(check == 1){
        printf("True");
    }else{
        printf("false");
    }
    return 0;
}
