#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFSIZE 1 << 17
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

typedef struct{
    int nA, nB;
    int w;
}Edge;
Edge edge[100001];
int parent[1001];
int N, M;

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    if(y > x) parent[y] = x;
    else parent[x] = y;
    return true;
}

int compare(const void *a, const void *b){
    Edge A = *(Edge*)a;
    Edge B = *(Edge*)b;
    if(A.w > B.w) return 1;
    return -1;
}

int main(void){
    N = ReadInt();
    for(int i = 1; i <= N; i++) parent[i] = i;

    M = ReadInt();
    for(int i = 0; i < M; i++){
        edge[i].nA = ReadInt();
        edge[i].nB = ReadInt();
        edge[i].w = ReadInt();
    }
    qsort(edge, M, sizeof(Edge), compare);

    int e = 0;
    int idx = 0;
    int ans = 0;
    while(e < N - 1){
        bool res = Union(edge[idx].nA, edge[idx].nB);
        if(res){
            ans += edge[idx].w;
            e++;
        }
        idx++;
    }
    printf("%d\n", ans);
}