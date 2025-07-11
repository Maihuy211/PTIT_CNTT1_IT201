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
int isEmpty(Queue *queue){
    if(queue->front == NULL){
        return 1;
    }
    return 0;
}
void dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("queue is empty");
        return;
    }
    Node *temp = queue->front;
    queue->front=queue->front->next;
    if(queue->front==NULL){
        queue->rear = NULL;
    }
    free(temp);
}
void printQueue(Queue* queue){
    Node* current = queue->front;
    printf("front -> ");
    while(current != NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL");
    printf("\nrear -> ");
    if(queue->rear != NULL ){
        printf("%d -> NULL",queue->rear->data);
    }else{
        printf("NULL");
    }
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
    printQueue(queue);

    dequeue(queue);
    printf("\nsau khi lay: \n");
    printQueue(queue);
    return 0;
}

