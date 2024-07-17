#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define BUFSIZE 1 << 20
typedef long long lnt;
char readubf[BUFSIZE];
int rp = BUFSIZE;
char ReadChar(){
    if(rp == BUFSIZE){
        fread(readubf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readubf[rp++];
}
lnt ReadInt(){
    char c;
    lnt ret = 0;
    while(c < '0' || c > '9') c = ReadChar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

typedef struct{
    int vertex;
    lnt dis; // time
}Vertex;
typedef struct{
    int capacity;
    int size;
    Vertex *vertice;
}Vecter;

Vecter *adj[100001];
Vertex *heap[100001];
lnt d[100001];
lnt N, M;
int heapsize;

void pushback(int a, int b, int t){
    if(adj[a]->capacity == adj[a]->size){
        adj[a]->capacity <<= 1;
        adj[a]->vertice = realloc(adj[a]->vertice, sizeof(Vertex) * adj[a]->capacity);
    }
    Vertex new = {b, t};
    adj[a]->vertice[adj[a]->size++] = new;
}

void insert(Vertex *item){
    int i = ++heapsize;
    while(i != 1 && item->dis < heap[i >> 1]->dis){
        heap[i] = heap[i >> 1];
        i >>= 1;
    }
    heap[i] = item;
}
Vertex *delete(){
    Vertex *item = heap[1];
    Vertex *temp = heap[heapsize--];
    int parent = 1, child = 2;

    while(child <= heapsize){
        if(child < heapsize && heap[child]->dis > heap[child | 1]->dis) child++;
        if(temp->dis <= heap[child]->dis) break;
        heap[parent] = heap[child];
        parent = child;
        child <<= 1;
    }
    heap[parent] = temp;
    return item;
}

void dijkstra(int src){
    memset(d, 0x7f, sizeof(d));
    d[src] = 0;
    Vertex *srcV = (Vertex*)malloc(sizeof(Vertex));
    srcV->dis = 0;
    srcV->vertex = src;
    insert(srcV);

    while(heapsize){
        Vertex *nowV = delete();
        int now = nowV->vertex;
        if(d[now] < nowV->dis) continue;
        for(int i = 0; i < adj[now]->size; i++){
            int nextV = adj[now]->vertice[i].vertex;
            lnt nextT = adj[now]->vertice[i].dis;
            lnt temp = nowV->dis % M;
            temp = nextT - temp;
            if(temp < 0) temp += M;
            lnt nextTime = temp + nowV->dis;

            if(d[nextV] > nextTime + 1){
                d[nextV] = nextTime + 1;
                Vertex *new = (Vertex*)malloc(sizeof(Vertex));
                new->dis = d[nextV];
                new->vertex = nextV;
                insert(new);
                // printf("%d -> %d, curtime = %lld, wait = %lld nowdis = %lld nextT = %lld\n", now, nextV, d[now], wait, nowV->dis, nextT);
            }
        }
    }
}

int main(void){
    lnt a, b;
    N = ReadInt(), M = ReadInt();
    for(int i = 0; i <= N; i++){
        adj[i] = (Vecter*)malloc(sizeof(Vecter));
        adj[i]->capacity = 2;
        adj[i]->size = 0;
        adj[i]->vertice = (Vertex*)malloc(sizeof(Vertex) * 2);
    }
    for(int i = 0; i < M; i++){
        a = ReadInt(), b = ReadInt();
        pushback(a, b, (lnt)i);
        pushback(b, a, (lnt)i);
    } 
    dijkstra(1);
    printf("%lld\n", d[N]);
}