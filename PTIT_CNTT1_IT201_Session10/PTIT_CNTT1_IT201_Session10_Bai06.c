#include <stdio.h>
#include <stdlib.h> 

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int data){
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode; 
}

void printList(Node* head){
    Node* current = head;
    while(current!=NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");

}

int lengthList(Node* head){
    Node* current = head;
    int length = 0;
    while(current!=NULL){
        length++;
        current = current->next;
    }
    return length;
}

void  search(Node* head){
    int length = lengthList(head);
    int midIndex =( length / 2 ) + 1;
    Node* current = head;
    int index = 1 ;
    while(index < midIndex){
        current = current->next;
        index++;
    }
    printf("Node %d: %d",index,current->data);
}
int main() {
    Node* head = createNode(1);
    Node* Node1 = createNode(2);
    Node* Node2 = createNode(3);
    Node* Node3 = createNode(4);
    Node* Node4 = createNode(5);

    head->next = Node1;
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;

    printList(head);
    search(head);
    return 0;
}