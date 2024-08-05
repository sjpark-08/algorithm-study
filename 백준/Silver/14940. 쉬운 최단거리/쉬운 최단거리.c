#include <stdio.h>
#define SIZE 1000000

typedef struct{
    int x;
    int y;
}P;
int graph[1001][1001];
int visited[1001][1001] = {0};
int n, m;
P queue[SIZE];
int front = 0, rear = 0;
int src_x, src_y;
int none = 0;

void push(P data){
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
}
P pop(){
    front = (front + 1) % SIZE;
    return queue[front];
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(){
    P src;
    src.x = src_x;
    src.y = src_y;
    push(src);
    graph[src_x][src_y] = 0;
    visited[src_x][src_y] = 1;

    while(front != rear){
        P cur = pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1) continue;
            if(!visited[nx][ny] && graph[nx][ny] == 1){
                P new;
                new.x = nx;
                new.y = ny;
                push(new);
                graph[nx][ny] = graph[cur.x][cur.y] + 1;
                visited[nx][ny] = 1;
            }
        }
    }
    return;
}

int main(void){
    int i, j;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++){
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 2){
                src_x = i;
                src_y = j;
            }
        }
    BFS();
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(!visited[i][j] && graph[i][j])
                printf("-1 ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}