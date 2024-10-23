#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void insert(int queue[], int *front, int *rear) {
    int value;
    if (*rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert more elements.\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        if (*front == -1) {
            *front = 0;
        }
        (*rear)++;
        queue[*rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

void delete(int queue[], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow! The queue is empty.\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[*front]);
        (*front)++;
        if (*front > *rear) {
            *front = *rear = -1;
        }
    }
}

void display(int queue[], int front, int rear) {
    if (front == -1) {
        printf("The queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(queue, &front, &rear);
                break;
            case 2:
                delete(queue, &front, &rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
