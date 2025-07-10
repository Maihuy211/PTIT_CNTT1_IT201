#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front; // dau hang
    int cap;
    int rear; // cuoi hang
}Queue;

Queue *createQueue(int cap){
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->front = 0;
    queue->rear = -1;
    queue->cap = cap;
    queue->arr = (int*)malloc(sizeof(int)*cap);
    return queue;
}

int isEmpty(Queue *queue){
    if(queue->rear < queue->front){
        return 1;
    }
    return 0;
}
int main(){
    Queue *queue = createQueue(5);
    if(isEmpty(queue)){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}

