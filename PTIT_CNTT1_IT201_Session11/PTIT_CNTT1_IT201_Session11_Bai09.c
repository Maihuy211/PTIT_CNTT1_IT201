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

Node* reverseList(Node* head){
    Node* current = head;
    Node* temp = NULL;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;
    }
    if(temp != NULL){
        head = temp->prev;

    }
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
    
    printf("dang sach dao nguoc la: \n");
    head = reverseList(head);
    printNode(head);
    return 0;
}