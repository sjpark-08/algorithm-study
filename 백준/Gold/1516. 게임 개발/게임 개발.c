#include <stdio.h>
#include <stdbool.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define BUFSIZE 1 << 16

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
    bool sign = false;

    while(c < '0'){
        if(c == '-') sign = true;
        c = ReadChar();
    }
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return sign ? -ret : ret;
}

int adj[501][501];
int queue[501];
int time[501], sum[501], indegree[501];
int front = -1, rear = -1, N;

void push(int data){
    queue[++front] = data; 
}
int pop(){
    return queue[++rear];
}
void adjpush(int a, int b){
    adj[a][++adj[a][0]] = b;
}

void topo(){
    for(int i = 1; i <= N; i++){
        int cur = pop();
        int len = adj[cur][0];
        for(int k = 1; k <= len; k++){
            int next = adj[cur][k];
            if(!indegree[next]) continue;
            if(!(--indegree[next])){
                push(next);
            }
            sum[next] = Max(sum[next], time[next] + sum[cur]);
        }
    }
}

int main(void){
    N = ReadInt();
    for(int i = 1; i <= N; i++){
        time[i] = sum[i] = ReadInt();
        sum[i] = time[i];
        int prev = ReadInt();
        while(prev != -1){
            adjpush(prev, i);
            indegree[i]++;
            prev = ReadInt();
        }
    }
    for(int i = 1; i <= N; i++){
        if(!indegree[i]) push(i);
    }
    topo();
    for(int i = 1; i <= N; i++) printf("%d\n", sum[i]);
}