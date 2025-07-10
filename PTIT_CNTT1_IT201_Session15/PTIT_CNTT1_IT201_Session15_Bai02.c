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
int isFull(Queue *queue) {
    if (queue->rear >= queue->cap - 1) {
        return 1; 
    } 
    return 0; 
}

int isEmpty(Queue *queue){
    if(queue->rear < queue->front){
        return 1;
    }
    return 0;
}
void enQueue(Queue *queue , int value){
    queue->rear++;
    queue->arr[queue->rear] = value;
}

void printQueue(Queue *queue){
    if(!isEmpty(queue)){
        for(int i = queue->front; i <= queue->rear; i++){
            printf("%d ", queue->arr[i]);
        }
    }
}

int main(){
    int cap;
    printf("nhap cap: ");
    scanf("%d",&cap);
    Queue *queue = createQueue(cap);
    int value;
    printf("nhap 5 phan tu: \n");
    for(int i = 0; i < 5; i++){
        scanf("%d",&value);
        enQueue(queue,value);
    }
    if(isFull(queue)){
        printQueue(queue);
    }else{
        printf("queue is full");
    }
    return 0;
}

