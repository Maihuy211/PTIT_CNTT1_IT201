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
        printf("Node %d: %d\n",index,current->data);
        index++;
        current = current->next;
    }
}
void searchList(Node* head, int x){
    Node* current = head;
    int check=0;
    while(current!=NULL){
        if(current->data == x){
            check=1;
            break;
        }
        current = current->next;
    }
    if(check){
        printf("True");
    }else{
        printf("False");
    }
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

    int number;
    printf("nhap mot so: ");
    scanf("%d",&number);
    searchList(head,number);
    return 0;
}