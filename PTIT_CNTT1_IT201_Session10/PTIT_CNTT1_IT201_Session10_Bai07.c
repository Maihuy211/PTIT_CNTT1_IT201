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
void sort(Node* head){
    Node* current = head;
    while(current != NULL){
        Node* minNode = current;
        Node* temp = current->next;

        while(temp != NULL){
            if(temp->data < minNode->data){
                minNode = temp;
            }
            temp = temp->next;
        }

        if(minNode != current){
            int tmp = current->data;
            current->data = minNode->data;
            minNode->data = tmp ;
        }

        current = current->next;
    }
}
int main() {
    Node* head = createNode(1);
    Node* Node1 = createNode(3);
    Node* Node2 = createNode(4);
    Node* Node3 = createNode(5);
    Node* Node4 = createNode(2);

    head->next = Node1;
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;

    printList(head);
    printf("\n");
    sort(head);
    printList(head);

    return 0;
}