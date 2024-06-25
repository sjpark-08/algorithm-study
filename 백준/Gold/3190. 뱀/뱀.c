#include <stdio.h>
#include <stdbool.h>
#define SIZE 101

typedef struct{
    int x, y;
}Point;
typedef struct{
    int t;
    char d;
}Query;

Point queue[SIZE];
Query query[SIZE];
bool map[SIZE][SIZE], apple[SIZE][SIZE];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int front = -1, rear = -1;
void push(Point data){
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
}
Point pop(){
    front = (front + 1) % SIZE;
    return queue[front];
}

int main(void){
    int N, K, L, x, y, t;
    char c;
    scanf("%d", &N);
    scanf("%d", &K);
    while(K--){
        scanf("%d %d", &x, &y);
        apple[x][y] = true;
    }

    // init
    int direction = 0;
    int time = 0;
    Point src = {1, 1};
    push(src);
    map[1][1] = true;

    scanf("%d", &L);
    for(int i = 0; i < L; i++) scanf("%d %c", &query[i].t, &query[i].d);
    int idx = 0;

    while(true){
        // expand 
        time++;
        int nx = queue[rear].x + dx[direction];
        int ny = queue[rear].y + dy[direction];
        if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny]) break;
        Point next = {nx, ny};
        push(next);
        map[nx][ny] = true;

        // apple
        if(apple[nx][ny]) apple[nx][ny] = false;
        else{
            Point out = pop();
            map[out.x][out.y] = false;
        }

        if(query[idx].t != time || idx == L) continue;

        if(query[idx].d == 'D') direction = (direction + 1) % 4;
        else if(query[idx].d == 'L') direction = (direction - 1 + 4) % 4;
        idx++;
    }
        
    printf("%d\n", time);
}