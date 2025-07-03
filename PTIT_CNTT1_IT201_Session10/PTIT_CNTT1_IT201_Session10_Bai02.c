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
    int index = 1;
    while(current!=NULL){
        printf("Data: %d\n",current->data);
        index++;
        current = current->next;
    }
}
int main() {
    Node* head = createNode(5);
    Node* Node1 = createNode(4);
    Node* Node2 = createNode(3);
    Node* Node3 = createNode(2);
    Node* Node4 = createNode(1);

    head->next = Node1;
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;

    printList(head);
    return 0;
}