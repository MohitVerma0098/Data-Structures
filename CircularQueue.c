#include<stdio.h>
#define MAX 5
void enqueue(int queue[],int *front, int *rear,int element){
    if(*rear==MAX-1){
        printf("Overflow\n");
    }
    else{
        if(*front==-1){
            (*front)++;
            (*rear)++;
        }
        else{
            (*rear)=((*rear)+1)%MAX;
        }
        queue[*rear]=element;
    }
}
void display(int queue[],int *front, int *rear){
    if(*front > *rear || (*front==*rear)==-1){
        printf("Empty queue\n");
    }
    else{
        printf("\n");
        for(int i =*front;i<=*rear;i++){
            printf("%d <- ",queue[i]);
        }
    }
    printf("NULL\n");
}
void dequeue(int queue[],int *front, int *rear){
    if(*front > *rear || *front==*rear==-1){
        printf("Underflow\n");
    }
    else{
        (*front)=((*front)+1)%MAX;
    }
}
int main(){
    int queue[MAX];
    int front=-1;
    int rear=-1;
    int choice;
    int loop=0;
    while(loop==0){
        printf("Select the operation\n");
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to insert\n");
                int element;
                scanf("%d",&element);
                enqueue(queue,&front,&rear,element);
                break;
            case 2:
                dequeue(queue,&front,&rear);
                break;
            case 3:
                display(queue,&front,&rear);
                break;
            case 4:
                printf("Exiting...\n");
                loop=-1;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}