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

int getlength(Node* head){
    Node* current = head;
    int length=0;
    while(current != NULL){
        current = current->next;
        length++;
    }
    return length;
}
void search(Node* head){
    int length = getlength(head);
    int midIndex =length / 2 ;
    Node* current = head;
    int index = 0 ;
    while(current != NULL && index < midIndex){
        current = current->next;
        index++;
    }
    printf("Node %d: %d",index,current->data);
}
int main(){
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    Node* node6 = createNode(6);

    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    node5->next = node6;
    node6->prev = node5;

    printNode(head);
    search(head);

    return 0;
}