#include <stdio.h>

#define INF 9999
#define N 6

char dugumler [N] = {'A','B','C','D','E','F'};

void yoluYazdir(int path[N], int target){
    int rota[N];
    int adim = 0;
    int curr = target;

    while (curr != -1){
        rota[adim++] = curr;
        curr = path[curr];
    }
    for(int i = adim -1 ; i >= 0 ; i--){
        printf("%c", dugumler[rota[i]]);
        if(i != 0)
        printf("->");
    }
}
int dijkstra(int graph[N][N], int start){
    int known[N];
    int distance[N];
    int path[N];

    for (int i = 0; i < N; i++){
        known[i] = 0;
        distance[i] = INF;
        path[i] = -1;
    }

    distance[start] = 0;

    for (int count = 0; count < N; count++){
        int min = INF;
        int u = -1;

        for (int i = 0; i < N ; i++){
            if (distance[i] < min && known[i] == 0){
                min = distance[i];
                u = i;
            }
        }
        if (u == -1)
        break;

        known[u] = 1;

        for (int v = 0; v < N ; v++){
            if (known[v] == 0 && graph[u][v] != 0 && distance[u] + graph[u][v] < distance[v]){
                distance[v] = distance[u] + graph[u][v];
                path[v] = u;
            }
        }
    }
    printf("Dugum\tKnown\tDistance\tPath\n");

    for (int i = 0; i < N ; i++){
        printf("%c\t%d\t%d\t\t",dugumler[i],known[i],distance[i]);
        if (path[i] == -1)
        printf("-\n");
        else
        printf("%c\n", dugumler[path[i]]);
    }
    if (start == 0){
        printf("\n\nA'dan B'ye en kisa yol:\n");
        yoluYazdir(path,1);
        printf("\nToplam maliyet: %d\n", distance[1]);
        printf("\n\nA'dan D'ye en kisa yol:\n");
        yoluYazdir(path,3);
        printf("\nToplam maliyet: %d\n", distance[3]);
    }
    int toplamMaliyet = 0;
    for (int i = 0; i < N ; i++){
        toplamMaliyet += distance[i];
    }

    return toplamMaliyet;
}

int main(){
    int graph[N][N] = {0};
    
    graph [0][1] = 7;
    graph [1][0] = 7;
    graph [0][2] = 5;
    graph [2][0] = 5;
    graph [0][5] = 1;
    graph [5][0] = 1;
    graph [1][2] = 1;
    graph [2][1] = 1;
    graph [1][3] = 1;
    graph [3][1] = 1;
    graph [1][4] = 3;
    graph [4][1] = 3;
    graph [2][3] = 2;
    graph [3][2] = 2;
    graph [2][4] = 1;
    graph [4][2] = 1;
    graph [3][5] = 7;
    graph [5][3] = 7;
    graph [4][5] = 2;
    graph [5][4] = 2;

    int enDusukMaliyet = INF;
    int merkeziDugum = -1;

    for (int i = 0; i < N; i++){
        int maliyet = dijkstra(graph,i);
        printf("\n%c dugumunun maliyeti: %d\n\n", dugumler[i], maliyet);

        if(maliyet < enDusukMaliyet){
            enDusukMaliyet = maliyet;
            merkeziDugum = i;
        }
    }

    printf("\n\nMerkezi dugum: %c\nEn dusuk maliyet: %d", dugumler[merkeziDugum], enDusukMaliyet);

    return 0;
}