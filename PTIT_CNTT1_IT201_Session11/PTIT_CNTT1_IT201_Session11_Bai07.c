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
    while(current != NULL){
        printf("%d <-> ",current->data);
        current = current->next;  
    }
    printf("NULL\n");
}

int getLength(Node* head){
    Node* current = head;
    int length=0;
    while(current != NULL){
        current = current->next;
        length++;
    }
    return length;
}
Node* insertHead(Node* head , int value){
    Node* newNode = createNode(value);
    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    return newNode;
}

Node* insertEnd(Node* head , int value){
    Node* newNode = createNode(value);
    if(head == NULL){
        return newNode;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

Node* insertAt(Node* head , int value ,int index){
    if(index < 0 || index > getLength(head)){
        printf("khong hop le");
        return head;
    }
    if(index == 0 ){
        return insertHead(head,value);
    }
    if(index == getLength(head) - 1){
        return insertEnd(head,value);
    }
    Node* current = head;
    for(int i = 0 ; i < index ; i++){
        current = current->next ;
    }
    Node* newNode = createNode(value);
    Node* prev = current->prev;

    newNode->next = current;
    current->prev = newNode;

    prev->next = newNode;
    newNode->prev = prev;

    return head;

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
    
    int value, position;
    printf("value: ");
    scanf("%d",&value); 
    printf("position: ");
    scanf("%d",&position);
    head = insertAt(head,value,position-1);
    printNode(head);
    return 0;
}