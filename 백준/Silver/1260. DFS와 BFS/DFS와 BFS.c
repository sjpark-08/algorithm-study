#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define BUFSIZE 1 << 15
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

bool visited[1001], graph[1001][1001];
int queue[10001];
int front = -1, rear = -1;
int N, M, V, a, b;

void push(int data){
    rear = (rear + 1) % 10001;
    queue[rear] = data;
}
int pop(){
    front = (front + 1) % 10001;
    return queue[front];
}

void DFS(int depth, int now){
    if(depth == N) return;
    visited[now] = true;
    printf("%d ", now);
    for(int i = 1; i <= N; i++){
        int next = i;
        if(!graph[now][next] || visited[next]) continue;
        DFS(depth + 1, next);
    }
}
void BFS(int src){
    push(src);

    while(front != rear){
        int now = pop();
        if(visited[now]) continue;
        visited[now] = true;
        printf("%d ", now);
        for(int i = 1; i <= N; i++){
            int next = i;
            if(!graph[now][next] || visited[next]) continue;
            push(next);
        }
    }
}

int main(void){
    N = ReadInt(), M = ReadInt(), V = ReadInt();
    while(M--){
        a = ReadInt(), b = ReadInt();
        graph[a][b] = true;
        graph[b][a] = true;
    }

    DFS(0, V);
    memset(visited, false, sizeof(visited));
    printf("\n");
    BFS(V);
}