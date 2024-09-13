#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack of characters
typedef struct {
    char* data;
    int top;
    int capacity;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->data = (char*) malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push a character onto the stack
void push(Stack* stack, char digit) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->data[++stack->top] = digit;
}

// Function to pop a character from the stack
char pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to add two numbers represented as stacks
void addNumbers(Stack* num1, Stack* num2, Stack* result) {
    int carry = 0;
    while (num1->top != -1 || num2->top != -1 || carry) {
        int digit1 = num1->top != -1 ? num1->data[num1->top--] - '0' : 0;
        int digit2 = num2->top != -1 ? num2->data[num2->top--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        push(result, (sum % 10) + '0');
    }
}

// Function to print a number represented as a stack
void printNumber(Stack* num) {
    while (num->top != -1) {
        printf("%c", pop(num));
    }
    printf("\n");
}

int main() {
    int capacity = 100; // adjust this to accommodate the maximum number of digits
    Stack* num1 = createStack(capacity);
    Stack* num2 = createStack(capacity);
    Stack* result = createStack(capacity);

    printf("Enter the first number (from most significant digit to least): ");
    char digit;
    while ((digit = getchar()) != '\n') {
        push(num1, digit);
    }

    printf("Enter the second number (from most significant digit to least): ");
    while ((digit = getchar()) != '\n') {
        push(num2, digit);
    }

    addNumbers(num1, num2, result);
    printf("Result: ");
    printNumber(result);

    return 0;
}