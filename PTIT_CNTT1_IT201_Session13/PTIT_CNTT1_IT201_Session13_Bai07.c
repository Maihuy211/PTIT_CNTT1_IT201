#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *open;
    char *close;
    int top1;
    int top2;
    int cap1;
    int cap2;
} Stack;

Stack *createStack(int cap1, int cap2) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top1 = -1;
    stack->top2 = -1;
    stack->cap1 = cap1;
    stack->cap2 = cap2;

    stack->open = (char *)malloc(sizeof(char) * cap1);
    stack->close = (char *)malloc(sizeof(char) * cap2);
    return stack;
}

void push_open(Stack *stack, char val) {
    if (stack->top1 >= stack->cap1 - 1) {
        printf("Open stack overflow\n");
        return;
    }
    stack->open[++(stack->top1)] = val;
}

void push_close(Stack *stack, char val) {
    if (stack->top2 >= stack->cap2 - 1) {
        printf("Close stack overflow\n");
        return;
    }
    stack->close[++(stack->top2)] = val;
}

int brackets(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

void check(char *str) {
    int len = strlen(str);
    Stack *stack = createStack(100, 100); 
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push_open(stack, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            push_close(stack, str[i]);
        }
    }
    if (stack->top1 != stack->top2) {
        printf("false");
        free(stack->open);
        free(stack->close);
        free(stack);
        return;
    }
    for(int i = 0; i <= stack->top1; i++){
        if(!brackets( stack->open[i], stack->close[stack->top1 - i])){
            printf("false");
            free(stack->open);
            free(stack->close);
            free(stack);
            return;
        }
    }
    printf("true");
    free(stack->open);
    free(stack->close);
    free(stack);
}

int main() {
    char str[100];

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    check(str);

    return 0;
}
