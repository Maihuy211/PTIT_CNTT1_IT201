#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct Queue{
    char arr[MAX][30];
    int front;
    int rear;
}Queue;

Queue *createQueue(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isFull(Queue *queue) {
    if (queue->rear >= MAX - 1) {
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
void enQueue(Queue *queue , char name[]){
    if(isFull(queue)){
        printf("khong the them khach moi");
        return;
    }
    queue->rear++; 
    strcpy(queue->arr[queue->rear], name);
}
void deQueue(Queue *queue){
    if (!isEmpty(queue)) { 
        printf("Dang phuc vu khach: %s\n", queue->arr[queue->front]); 
        queue->front++; 
    } else { 
        printf("Hang doi rong\n"); 
    }
}
void printQueue(Queue *queue){
    if(!isEmpty(queue)){
        for(int i = queue->front; i <= queue->rear; i++){
            printf("%s \n", queue->arr[i]);
        }
    }
}
int main(){
    Queue *queue = createQueue(); 
    int choice;
    char name[30];

    do{
        printf("\n");
        printf("\n1.Them khach hang moi vao hang doi\n");
        printf("2.Phuc vu khach\n");
        printf("3.Hien thi danh sach khach dang cho\n");
        printf("4.Thoat chuong trinh\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d",&choice);
        getchar();
        
        switch(choice){
            case 1:
                if(isFull(queue)){
                    printf("Khong the them khach moi\n");
                }else{
                    printf("Nhap ten khach moi: ");
                    fgets(name,30,stdin);
                    name[strcspn(name,"\n")] = '\0';
                    enQueue(queue,name);
                }
                break;
            case 2:
                deQueue(queue);
                break;
            case 3:
                printf("danh sanh hang dang cho ");
                printQueue(queue);
                break;
            case 4:
                printf("thoat chuong trinh ");
                break;
            default:
                printf("Lua chon khong hop le ");

        }
    }while(choice != 4);
    return 0;
}