#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node ;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data ;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printNode(Node* head){
    Node* current = head;
    int index=1;
    while(current != NULL){
        printf("Node %d: %d\n",index,current->data);
        index++;
        current = current->next;
        
    }
}
void search(Node* head , int x){
    Node* current = head;
    int check=1;
    while(current != NULL){
        if(current->data == x){
            printf("True");
            check=0;
        }
        current = current->next;
    }
    if(check==1) printf("False");
}
int main(){
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;
    
    
    printNode(head);
     
    int numbers;
    printf("Nhap mot so: ");
    scanf("%d",&numbers);

    search(head,numbers);
    return 0;
}