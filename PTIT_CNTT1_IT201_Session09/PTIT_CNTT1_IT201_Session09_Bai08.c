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
Node* remeveLast(Node* head){
    if(head==NULL) return NULL;
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    Node* current = head;
    while(current->next->next != NULL){
        current = current->next;
    }
    Node* removeNode = current->next;
    current->next = NULL;
    free(removeNode);
    return head;

}
Node* removeAt(Node* head ,int index) {
    if(index < 0 || index > lengthList(head)){
        printf("khong hop le");
        return head;
    }
    if(index==0){
        return removeHead(head);
    }
    if(index==lengthList(head)-1){
        return remeveLast(head);  
    }
    Node* current = head;
    for(int i = 0 ; i < index - 1 ; i++){
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
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
    int index;
    printf("nhap vi tri muon xoa: ");
    scanf("%d",&index);

    head = removeAt(head,index-1);
    printList(head);
    
    return 0;
}