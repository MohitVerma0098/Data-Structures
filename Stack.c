#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void push(int stack[], int *top) {
    int value;
    if (*top == SIZE - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[*top]);
        (*top)--;
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int stack[SIZE];
    int top = -1;
    int choice;
    
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
