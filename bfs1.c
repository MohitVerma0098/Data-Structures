#include<stdio.h>
#define MAX 5

void bfs(int adj[][MAX],int visited[],int start){
    int queue[MAX];
    int front=-1,rear=-1,i,k;
    for(k=0;k<MAX;k++){
        visited[k]=0;
    }
    queue[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear>=front){
        start=queue[front++];
        printf("%c-> ",start+65);
        for(i=0;i<MAX;i++){
            if(adj[start][i] && visited[i]==0){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main(){
    int visited[MAX]={0};
    int adj[MAX][MAX];
    int choice=1;
    while(choice!=3){
        printf("Enter the operation : \n");
        printf("1. Input the adjacency matrix\n");
        printf("2. BFS Traversal\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the adjacency matrix \n");
                for(int i=0;i<MAX;i++){
                    for(int j=0;j<MAX;j++){
                        scanf("%d",&adj[i][j]);
                    }
                }
            case 2:
                bfs(adj,visited,0);
            case 3:
                printf("Exiting\n");
                choice=3;
        }
    }
}
