#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
typedef struct Queue {
    Node **arr;
    int cap;
    int front;
    int rear;
} Queue;
Queue *createQueue(int cap) {
    Queue *newQueue = (Queue *) malloc(sizeof(Queue));
    newQueue->arr = (Node **) malloc(sizeof(Node *) * cap);
    newQueue->cap = cap;
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}
void enqueue(Queue *queue, Node *node) {
    if (queue->rear == queue->cap - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[++queue->rear] = node;
}
int isEmpty(Queue *queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}
Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}
void levelorder(Node* root){
    if(root == NULL){
        return;
    }
    Queue *queue = createQueue(100);

    enqueue(queue,root);
    while(!isEmpty(queue)){
        Node *node = queue->arr[queue->front++];
        printf("%d\n",node->data);

        if(node->left != NULL){
            enqueue(queue,node->left);
        }
        if(node->right != NULL){
            enqueue(queue,node->right);
        }
    }
}

Node *delete(Node *root, int value) {
    if (root == NULL) {
        return NULL;
    }
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    Node *target = NULL;
    Node *lastNode = NULL;
    Node *lastParent = NULL;
    while (!isEmpty(queue)) {
        Node *node = dequeue(queue);
        if (node->data == value) {
            target = node;
        }
        if (node->left != NULL) {
            enqueue(queue, node->left);
            lastParent = node;
            lastNode = node->left;
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
            lastParent = node;
            lastNode = node->right;
        }
    }
    if (target == NULL) {
        free(queue->arr);
        free(queue);
        return root;
    }
    if (lastNode == NULL) {
        free(root);
        root = NULL;
    }else {
        target->data = lastNode->data;
        if (lastNode == lastParent->left) {
            lastParent->left = NULL;
        }else {
            lastParent->right = NULL;
        }
        free(lastNode);
    }
    free(queue->arr);
    free(queue);
    return root;
}
int main(){
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    root->left->right = createNode(6);
    printf("\nlevelorder (BFS) \n");
    levelorder(root);

    int value;
    printf("nhap mot so can xoa: ");
    scanf("%d",&value);
    
    root = delete(root,value);
    levelorder(root);

}
