#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct People{
    char name[30];
    int age;
}People;

typedef struct Queue {
    People *queueOld;
    People *queueNormal;
    int front1; // dau han;
    int rear1;// cuoi hang
    int front2; // dau han;
    int rear2;// cuoi hang
    int cap;
}Queue;

Queue *createQueue(int cap){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->queueOld = (People*)malloc(sizeof(People)*cap);
    queue->queueNormal = (People*)malloc(sizeof(People)*cap);
    queue->front1 = 0;
    queue->rear1 = -1;
    queue->front2 = 0;
    queue->rear2 = -1;
    queue->cap = cap;
    return queue;
}
int isFullOld(Queue *queue) {
    if (queue->rear1 >= queue->cap - 1) {
        return 1; 
    } 
    return 0; 
}
int isFullNormal(Queue *queue) {
    if (queue->rear2 >= queue->cap - 1) {
        return 1; 
    } 
    return 0; 
}
int isEmptyOLd(Queue *queue){
    if(queue->rear1 < queue->front1){
        return 1;
    }
    return 0;
}
int isEmptyNormal (Queue *queue){
    if(queue->rear2 < queue->front2){
        return 1;
    }
    return 0;
}
void enQueue(Queue *queue  , char name[30] , int age){
    People people;
    strcpy(people.name , name);
    people.age = age;

    if(age >= 60){
        if(isFullOld(queue)){
            printf("khong the them ng gia");
            return;
        }
        queue->rear1++;
        queue->queueOld[queue->rear1] = people;
    }else{
        if(isFullNormal(queue)){
            printf("khong the them ng tre");
            return;
        }
        queue->rear2++;
        queue->queueNormal[queue->rear2] = people;
    }
    
}

void printQueue(Queue *queue){
    People people ;
    while(!isEmptyOLd(queue)){
        people = queue->queueOld[queue->front1++];
        printf("%s \n",people.name);
    }
    while(!isEmptyNormal(queue)){
        people = queue->queueNormal[queue->front2++];
        printf("%s \n",people.name);
    }
}
int main(){
    int cap;
    printf("nhap cap: ");
    scanf("%d",&cap);
    getchar();
    Queue *queue = createQueue(cap);
    char name[30];
    int age;
    printf("nhap thong tin nguoi muon phuc vu: \n");
    for(int i = 0; i < cap; i++){
        printf("nhap ten nguoi thu %d: ",i+1);
        fgets(name,30,stdin);
        name[strcspn(name,"\n")] = '\0';
        printf("nhap tuoi nguoi thu %d: ",i+1);
        scanf("%d",&age);
        getchar();
    
        enQueue(queue,name,age);
    }
    printf("thu tu dc phuc vu lan luot la: \n");
    printQueue(queue);
    return 0;
}

