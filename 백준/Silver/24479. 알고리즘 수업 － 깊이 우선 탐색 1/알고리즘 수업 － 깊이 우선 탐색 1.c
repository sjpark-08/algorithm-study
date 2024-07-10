#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1 << 17
char readbuf[BUFSIZE], writebuf[BUFSIZE];
int rp = BUFSIZE, wp = 0;
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
void WriteInt(int n){
    int tmp = n;
    int cnt = 0;
    while(tmp > 0){
        tmp /= 10;
        cnt++;
    }
    if(n == 0) cnt = 1;
    if(wp + cnt + 1 >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    writebuf[wp + cnt] = '\n';
    int len = cnt;
    while(cnt){
        cnt--;
        writebuf[wp + cnt] = n % 10 + 48;
        n /= 10;
    }
    wp += len + 1;
}

typedef struct{
    int Capacity;
    int size;
    int *vertice;
}ADJ;
ADJ *adj[100001];
int visit[100001];
int N, M, R, cnt;

int compare(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A > B) return 1;
    return -1;
}

void push(int a, int b){
    if(adj[a]->Capacity == adj[a]->size){
        adj[a]->Capacity <<= 1;
        adj[a]->vertice = (int*)realloc(adj[a]->vertice, adj[a]->Capacity * sizeof(int));
    }
    adj[a]->vertice[adj[a]->size++] = b;
}

void dfs(int now){
    visit[now] = ++cnt;
    for(int i = 0; i < adj[now]->size; i++){
        int next = adj[now]->vertice[i];
        if(visit[next]) continue;
        dfs(next);
    }
}

int main(void){
    int a, b;
    N = ReadInt(), M = ReadInt(), R = ReadInt();
    for(int i = 0; i <= N; i++){
        adj[i] = (ADJ*)malloc(sizeof(ADJ));
        adj[i]->Capacity = 2;
        adj[i]->size = 0;
        adj[i]->vertice = (int*)malloc(sizeof(int) * 2);
    }
    while(M--){
        a = ReadInt(), b = ReadInt();
        push(a, b);
        push(b, a);
    }
    
    for(int i = 1; i <= N; i++){
        if(adj[i]->size == 0) continue;
        qsort(adj[i]->vertice, adj[i]->size, sizeof(int), compare);
    }

    dfs(R);
    for(int i = 1; i <= N; i++) WriteInt(visit[i]);
    fwrite(writebuf, 1, wp, stdout);
}