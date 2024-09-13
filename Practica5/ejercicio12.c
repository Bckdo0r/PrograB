#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_STACK 100

typedef struct {
    int data[MAX_STACK];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top == MAX_STACK - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int evaluatePostfix(char* expression) {
    Stack stack;
    initStack(&stack);
    char token[2];
    int i = 0;
    while (expression[i] != '\0') {
        token[0] = expression[i];
        token[1] = '\0';
        if (isdigit(token[0])) {
            push(&stack, token[0] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (token[0]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero!\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Error: Invalid operator!\n");
                    exit(1);
            }
        }
        i++;
    }
    return pop(&stack);
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    fgets(expression, 100, stdin);
    expression[strcspn(expression, "\n")] = 0; // remove newline character
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}