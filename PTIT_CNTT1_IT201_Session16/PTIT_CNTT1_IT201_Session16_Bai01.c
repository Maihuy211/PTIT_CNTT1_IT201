#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Queue {
    Node* front; // dau hang
    Node* rear; // cuoi hang
}Queue;
Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Queue *createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int main(){
    Queue *queue = createQueue();
    
    Node *head = createNode(1);
    Node *node1 = createNode(2);
    Node *node2  = createNode(3);
    
    head->next = node1;
    node1->next = node2;

    queue->front=head;
    queue->rear=node2;
    return 0;
}



