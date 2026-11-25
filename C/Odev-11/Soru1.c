#include <stdio.h>

#define N 6

int main(){
    int graph[N][N] = {0};

    graph[0][1] = 1;
    graph[0][3] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[2][5] = 1;
    graph[3][4] = 1;
    graph[4][5] = 1;
    graph[1][0] = 1;
    graph[3][0] = 1;
    graph[2][1] = 1;
    graph[3][2] = 1;
    graph[5][2] = 1;
    graph[4][3] = 1;
    graph[5][4] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;
    
    int genelderece = 0;

    for(int i = 0 ; i < N ; i++){
        int derece = 0;
        for (int j = 0 ; j < N ; j++){
            if(graph[i][j] == 1)
            derece++;
        }
        printf("%d. dugumun derecesi : %d\n", i+1, derece);
        genelderece += derece;
    }

    printf("Genel derece: %d\n\n", genelderece);

    int color[N];
    
    for(int i = 0; i < N ; i++){
        color[i] = -1;
    }

    int isBipartite = 1;
    int queue [N];
    int front = 0;
    int rear = 0;

    color[0] = 0;
    queue[rear++] = 0;

    while(front < rear){
        int current = queue[front++];

        for(int i = 0; i < N ; i++){
            if(graph[current][i] == 1){
                if(color[i] == -1){
                    color[i] = 1 - color[current];
                    queue[rear++] = i;
                }
                else if(color[i] == color[current]){
                    isBipartite = 0;
                    break;
                }
            }
        }
    }
    
    if(isBipartite == 1){
        printf("Bu graf, bipartite bir graftir.\n");
        for (int i = 0; i < N ; i++){
            printf("%d. dugumun rengi = %d\n", i+1, color[i]);
        }
    }
    else
    printf("\nBu graf, bipartite graf degildir");

    return 0;
}