#include <stdio.h>

int graph[1001][1001] = {0};
int visited[1001] = {0};
int check[1001] = {0};
int result[1001] = {0};

int queue[100000] = {0};
int front = -1;
int rear = -1;

void push(int item){
    queue[++rear] = item;
}
int pop(){
    return queue[++front];
}

void DFS(int depth, int n, int v){
    int i;
    if(depth == n){
        return;
    }
    else if(depth == 0){
        result[depth] = v;
        printf("%d ", v);
        check[v] = 1;
        DFS(depth + 1, n, v);
    }
    else{
        for(i = 1; i <= n; i++){
            if(!check[i] && graph[result[depth - 1]][i]){
                result[depth] = i;
                printf("%d ", i);
                check[i] = 1;
                DFS(depth + 1, n, v);
            }
        }
    }
}

void BFS(int n, int v){
    visited[v] = 1;
    printf("%d ", v);
    push(v);

    while(front != rear){
        int vertex = pop();
        for(int i = 1; i <= n; i++){
            if(!visited[i] && graph[vertex][i]){
                push(i);
                printf("%d ", i);
                visited[i] = 1;
            }
        }
    }
}

int main(void){
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    int x, y;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }
    DFS(0, n, v);
    printf("\n");
    BFS(n, v);
}