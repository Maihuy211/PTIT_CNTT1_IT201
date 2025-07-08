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
    return stack;

}

int main(){
    int size = 5;
    Stack *stack = createStack(size);
    
    free(stack);
    return 0;
}



