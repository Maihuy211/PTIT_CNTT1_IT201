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

Node* delete(Node* head , int n){
    Node* current = head;
    Node* prev = NULL;

    while(current != NULL){
        if(current->data ==n){
            Node* temp = current;

            if(prev == NULL){
                head = current->next;
                if(head!= NULL){
                    head->prev = NULL;
                }
                current = head;
            }else{
                prev->next = current->next;
                if(current->next != NULL){
                    current->next->prev = prev;
                }
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
int main(){
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(5);
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
    int n;
    printf("nhap vao so nguyen duong bat ki: ");
    scanf("%d",&n);
    head = delete(head ,n);
    printNode(head);
    return 0;
}