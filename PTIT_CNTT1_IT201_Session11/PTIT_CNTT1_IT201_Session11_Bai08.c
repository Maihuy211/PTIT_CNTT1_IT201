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

Node* removeHead(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    free(temp);
    return head;
}

Node* removeEnd(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;

    }
    current->prev->next = NULL;
     
    free(current);
    return head;
}

Node* removeAt(Node* head , int index){
    if(index < 0 || index > getLength(head) - 1){
        printf("khong hop le");
    }
    if(index == 0 ){
        return removeHead(head);
    }
    if(index == getLength(head) - 1){
        return removeEnd(head);
    }
    Node* current = head;
    for(int i = 0 ; i < index ; i++){
        current = current->next;
    }
    

    Node* temp = current;

    Node* prev = current->prev;
    Node* next = current->next;
    
    prev->next = next;
    if(next != NULL){
        next->prev = prev;
    }
    free(temp);
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
    
    int position; 
    printf("position: ");
    scanf("%d",&position);
    head = removeAt(head,position-1);
    printNode(head);
    return 0;
}