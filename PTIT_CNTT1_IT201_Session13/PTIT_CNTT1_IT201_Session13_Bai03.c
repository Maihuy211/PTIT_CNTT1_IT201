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
int main(){

    int size = 5;
    Stack *stack = createStack(size);
    int val;
    printf("nhap 5 so: \n");
    for(int i = 0 ; i < size ; i++){
        scanf("%d",&val);
        push(stack,val);
        
    }
    for(int i = 0 ; i < size ; i++){
        printf("%d ",pop(stack));
    }
    free(stack->stack);
    free(stack);
    return 0;
    
}



