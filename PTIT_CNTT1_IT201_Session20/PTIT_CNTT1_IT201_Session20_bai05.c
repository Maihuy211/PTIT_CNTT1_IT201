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
int maxDFS(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }
    int max = root->data;
    if (root->left != NULL) {
        int leftMax = maxDFS(root->left);
        if (leftMax > max) {
            max = leftMax;
        }
    }
    if (root->right != NULL) {
        int rightMax = maxDFS(root->right);
        if (rightMax > max) {
            max = rightMax;
        }
    }
    return max;
}
int main(){
   Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("\nInorder (LNR) \n");
    inorder(root);
    

    int result = maxDFS(root);
    printf("max value: %d",result);
    return 0;
}