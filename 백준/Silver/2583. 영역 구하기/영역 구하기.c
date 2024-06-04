#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    int x, y;
}Point;
int M, N, K;
bool visited[102][102];
int map[102][102];
int land_num = 1;
int cnt;
int lands[103];
Point queue[10001];
int front, rear;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void push(Point data){
    queue[++rear] = data;
}
Point pop(){
    return queue[++front];
}
int compare(const void *a, const void *b){
    return *(int*)a > *(int*)b;
}

void BFS(int src_x, int src_y){
    front = -1, rear = -1;
    Point src = {src_x, src_y};
    push(src);
    visited[src_x][src_y] = true;
    cnt = 0;
    map[src_x][src_y] = land_num;
    while(front != rear){
        Point cur = pop();
        cnt++;
        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = true;
            map[nx][ny] = land_num;
            Point new = {nx, ny};
            push(new);
        }
    }
    lands[land_num++] = cnt;
}

int main(void){
    scanf("%d %d %d", &M, &N, &K);
    int x1, x2, y1, y2;
    while(K--){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i = y1; i < y2; i++){
            for(int j = x1; j < x2; j++){
                visited[i][j] = true;
            }
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j]) continue;
            BFS(i, j);
        }
    }
    qsort(lands, land_num, sizeof(int), compare);
    printf("%d\n", land_num - 1);
    for(int i = 1; i < land_num; i++) printf("%d ", lands[i]);
    printf("\n");
}