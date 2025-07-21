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
int high(Node* root){
    if(root == NULL){
        return -1;
    }
    int leftHigh = high(root->left);
    int rightHigh = high(root->right);

    if(leftHigh > rightHigh){
        return leftHigh + 1;
    }else{
        return rightHigh + 1;
    }
}
int main(){
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    printf("levelorder (BFS) \n");
    levelorder(root);
    int h = high(root);
    printf("\n%d",h);
    return 0;
}    
