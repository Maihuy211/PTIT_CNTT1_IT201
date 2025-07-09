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

int main(){
    Stack* stack = createStack();
    return 0;
}



