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

Node* insertHead(Node* head , int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;

}

Node* insertEnd(Node* head , int data){
    Node* newNode = createNode(data);
    if(head == NULL) return newNode;
    Node* current = head;
    while(current->next != NULL){
        current =current->next ;
    }
    current->next = newNode;
    return head;
}

Node* insertAt(Node* head , int data , int index){
    if(index < 0 || index > lengthList(head)){
        printf("khong hop le");
        return head;
    }
    if(index==0){
        return insertHead(head,data);
    }
    if(index==lengthList(head)){
        return insertEnd(head,data);
        
    }
    Node* newNode = createNode(data);
    Node* current = head;
    for(int i = 0 ; i < index - 1  ; i++){
        current =current->next ;
    }
    newNode->next = current->next;
    current->next =newNode;
    return head;
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
    int number,index;
    printf("\nvalue: ");
    scanf("%d",&number);
    printf("position: ");
    scanf("%d",&index);
    head = insertAt(head,number,index-1);
    printList(head);
    return 0;
}