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

Node* removeHead(Node* head){
    if(head==NULL) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
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
 
    head = removeHead(head);
    printf("sau khi xoa mot phan tu dau mang:\n");
    printList(head);
    
    return 0;
}