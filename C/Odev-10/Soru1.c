#include <stdio.h>
#include <stdlib.h>

#define N 5

char* sehirler [N] = {"istanbul", "ankara", "izmir", "bursa", "antalya"};

void DFS(int graph[N][N], int visited[N], int current){
    visited[current] = 1;

    printf("%s ", sehirler[current]);

    for(int i = 0; i < N ; i++){
    if (visited[i] == 0 && graph[current][i]){
        DFS(graph,visited,i);
        }
    }
}

void BFS(int graph[N][N], int visited[N], int start){
    int queue[N];
    int current, front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear){
        current = queue[front++];
        printf("%s ", sehirler[current]);

        for (int i = 0; i < N; i++){
            if (graph[current][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
int main(){
    int graph[N][N] = {0};

    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[0][3] = 1;
    graph[3][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[1][4] = 1;
    graph[4][1] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;

    int visitedD[N] = {0};

    DFS(graph,visitedD,0);

    printf("\n\n");

    int visitedB[N] = {0};

    BFS(graph,visitedB,0);


    return 0;
}