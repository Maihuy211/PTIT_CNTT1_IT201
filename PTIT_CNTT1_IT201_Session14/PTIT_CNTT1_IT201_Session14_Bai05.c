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

Stack *createStack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack *stack, int value){
    Node *newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}

void pop(Stack* stack) {
    if (stack->head == NULL) {
        printf("ngan xep rong\n");
        return;
    }
    Node* temp = stack->head;
    stack->head = temp->next;
    free(temp);
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

int peek(Stack *stack) {
    if (stack->head == NULL) {
        printf("ngan xep rong");
        return -1;
    }
    return stack->head->data;
}
int main(){
    Stack* stack = createStack();
    
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printStack(stack);

    int result = peek(stack);
    
    printf("\n");
    printf("%d",result);

    return 0;
}



