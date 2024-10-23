#include <stdio.h>
#include <ctype.h>

#define SIZE 100

void push(char stack[], int *top, char c) {
    if (*top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++(*top)] = c;
    }
}

char pop(char stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[(*top)--];
    }
}

char peek(char stack[], int top) {
    if (top == -1) {
        return -1;
    } else {
        return stack[top];
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix) {
    char stack[SIZE];
    char postfix[SIZE];
    int top = -1, i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        c = infix[i];

        if (isalnum(c)) {  // Operand, add to postfix expression
            postfix[j++] = c;
        } else if (c == '(') {
            push(stack, &top, c);
        } else if (c == ')') {
            while (peek(stack, top) != '(') {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top);  // Remove '(' from stack
        } else {  // Operator
            while (top != -1 && precedence(peek(stack, top)) >= precedence(c)) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, c);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop(stack, &top);
    }
    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[SIZE];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
