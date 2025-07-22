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

typedef struct Queue {
    Node **arr;
    int front;
    int cap;
    int rear; 
}Queue;

Queue *createQueue(int cap){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(sizeof(Node* )*cap);
    queue->front = 0;
    queue->rear = -1;
    queue->cap = cap;   
    return queue;
}
int isEmpty(Queue *queue){
    if(queue->rear < queue->front){
        return 1;
    }
    return 0;
}

void enQueue(Queue *queue , Node* value){
    queue->rear++;
    queue->arr[queue->rear] = value;
}

void preorder(Node* root){
    if(root != NULL){
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void portorder(Node* root){
    if(root != NULL){
        portorder(root->left);
        portorder(root->right);
        printf("%d\n", root->data);
    }
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

void levelorder(Node* root){
    if(root == NULL){
        return;
    }
    Queue *queue = createQueue(100);

    enQueue(queue,root);
    while(!isEmpty(queue)){
        Node *node = queue->arr[queue->front++];
        printf("%d\n",node->data);

        if(node->left != NULL){
            enQueue(queue,node->left);
        }
        if(node->right != NULL){
            enQueue(queue,node->right);
        }
    }
}

int main(){
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("\nPreorder (NLR) \n");
    preorder(root);

    printf("\nPortorder (LRN) \n");
    portorder(root);

    printf("\nInorder (LNR) \n");
    inorder(root);

    printf("\nlevelorder (BFS) \n");
    levelorder(root);

    return 0;
}
