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
Node* delete(Node* head , int n){
    Node* current = head;
    Node* prev = NULL;
    while(current != NULL){
        if(current->data == n){
            Node* temp = current;
            if(prev == NULL){
                head = current->next;
                current = head;
            }else{
                prev->next = current->next;
                current = current->next;
            }
            free(temp);
        }else{
            prev = current;
            current = current->next;
        }
    }
    return head; 
}
int main() {
    Node* head = createNode(5);
    Node* Node1 = createNode(4);
    Node* Node2 = createNode(3);
    Node* Node3 = createNode(5);
    Node* Node4 = createNode(2);
    Node* Node5 = createNode(1);
    Node* Node6 = createNode(5);

    head->next = Node1;
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next = Node5;
    Node5->next = Node6;

    printList(head);
    int n;
    printf("nhap vao so nguyen duong bat ki: ");
    scanf("%d",&n);
    head = delete(head ,n);
    printList(head);
    return 0;
}