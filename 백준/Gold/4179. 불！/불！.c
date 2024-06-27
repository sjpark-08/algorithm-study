#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#define BUFSIZE 1 << 18
char readbuf[BUFSIZE];
int rp = BUFSIZE;
char ReadChar(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
int ReadInt(){
    char c;
    int ret = 0;
    while(c < '0' || c > '9') c = ReadChar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}
#define SIZE 100000
typedef struct{
    int x, y;
}Point;
Point queue[SIZE];
int front = -1, rear = -1;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0 ,0};
int visit[1001][1001];
int visitFire[1001][1001];
char map[1001][1001];
int R, C;

void push(Point data){
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
}
Point pop(){
    front = (front + 1) % SIZE;
    return queue[front];
}

void bfsFire(){

    while(front != rear){
        Point cur = pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx > R - 1 || ny > C - 1) continue;
            if(visitFire[nx][ny] || map[nx][ny] == '#') continue;
            Point new = {nx, ny};
            push(new);
            visitFire[nx][ny] = visitFire[cur.x][cur.y] + 1;
        }
    }
}           
int bfs(Point src){
    push(src);
    while(front != rear){
        Point cur = pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx > R - 1 || ny > C - 1){
                return visit[cur.x][cur.y];
            }
            if(visit[nx][ny] || map[nx][ny] == '#') continue;
            if(visitFire[nx][ny] && visitFire[nx][ny] <= visit[cur.x][cur.y] + 1) continue;
            Point new = {nx, ny};
            push(new);
            visit[nx][ny] = visit[cur.x][cur.y] + 1;
        }
    }
    return -1;
}

int main(void){
    Point src;
    R = ReadInt(), C = ReadInt();
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            map[i][j] = ReadChar();
            if(map[i][j] == 'F'){
                Point srcFire;
                srcFire.x = i;
                srcFire.y = j;
                push(srcFire);
                visitFire[i][j] = 1;
            }else if(map[i][j] == 'J'){
                src.x = i;
                src.y = j;
                visit[i][j] = 1;
            }
        }
        ReadChar();
    }
    bfsFire();
    int ans = bfs(src);
    if(ans == -1) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
}