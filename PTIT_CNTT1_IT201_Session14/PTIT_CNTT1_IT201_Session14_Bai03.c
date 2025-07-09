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

typedef struct Stack {
    Node *head;
}Stack;

Stack *createStack(int cap){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack *stack, int value){
    Node *newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}

void printStack(Stack *stack){
    Node *current = stack->head;
    if (current == NULL) {
        return;
    }
    while (current != NULL) {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL");
}

int main(){
    Stack* stack = createStack(1);
    int n, value;
    printf("nhap n: ");
    scanf("%d", &n);
    if(n<0){
        printf("Ngan xep rong");
    }else{
         printf("nhap tu phan tu: \n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            push(stack, value);
        }
        printStack(stack);
    }
    return 0;
}
