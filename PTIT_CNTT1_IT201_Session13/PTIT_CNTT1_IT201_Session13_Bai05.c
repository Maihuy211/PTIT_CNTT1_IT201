#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int *stack;
    int top;
    int cap;
}Stack;

Stack *createStack(int cap){
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    stack->top = -1;
    stack->cap = cap;
    
    stack->stack = (int*)malloc(sizeof(int)*cap);  

    return stack;
}

int isfull(Stack *stack){
    if(stack->top == stack->cap-1){
        return 1;
    }
    return 0;
}
int push(Stack *stack , int val){
    if(isfull(stack)){
        printf("Stack overflow");
        return 0;
    }
    stack->top+=1;
    stack->stack[stack->top] = val;

    return 1;

}
int isEmpty(Stack *stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack underflow");
        return -1;
    }
    int temp = stack->stack[stack->top];
    stack->top--;
    return temp;
    
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int arr[], int n) {
    Stack *stack = createStack(n);
    for(int i = 0; i < n; i++){
        push(stack, arr[i]);
    }
    for(int i = 0; i < n; i++){
        arr[i] = pop(stack);
    }
    free(stack->stack);
    free(stack);
}
int main(){
    int size = 5;
    int arr[100];
    printf("nhap 5 so: \n");
    for(int i = 0 ; i < size ; i++){
        scanf("%d",&arr[i]);
    }
    printf("ban dau: ");
    printArray(arr, size);

    reverseArray(arr, size);

    printf("sau khi dao nguoc: ");
    printArray(arr, size);

    return 0;
}

