#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Stack {
    int top;
    int arr[MAX];
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int main() {
    struct Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    printf("%d popped from stack\n", pop(&stack));
    return 0;
}
