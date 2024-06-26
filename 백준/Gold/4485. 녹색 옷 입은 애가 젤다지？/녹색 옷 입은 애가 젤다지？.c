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

typedef struct _Node{
    int vertex;
    int dis;
    struct _Node *next;
}Node;
Node *adj[16000], *heap[16000];
bool visited[16000];
int d[16000], map[126][126];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int TC, N, heapsize;

void Insert(Node *head, int v, int d){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->dis = d;
    newNode->next = head->next;
    head->next = newNode;
}
void setAdj(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int now = i * N + j;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1) continue;
                int next = nx * N + ny;
                Insert(adj[now], next, map[nx][ny]);
            }
        }
    }
}

void insert(Node *item){
    int i = ++heapsize;
    while(i != 1 && item->dis < heap[i >> 1]->dis){
        heap[i] = heap[i >> 1];
        i >>= 1;
    }
    heap[i] = item;
}
Node *delete(){
    Node *item = heap[1];
    Node *temp = heap[heapsize--];
    int parent = 1, child = 2;

    while(child <= heapsize){
        if(child < heapsize && heap[child]->dis > heap[child|1]->dis) child++;
        if(temp->dis <= heap[child]->dis) break;
        heap[parent] = heap[child];
        parent = child;
        child <<= 1;
    }
    heap[parent] = temp;
    return item;
}

void dijkstra(){
    memset(d, 0x7f, sizeof(d));
    memset(visited, 0, sizeof(visited));
    d[0] = map[0][0];
    Node *src = (Node*)malloc(sizeof(Node));
    src->vertex = 0;
    src->dis = 0;
    insert(src);

    while(heapsize){
        Node *cur = delete();
        int curv = cur->vertex;
        if(visited[curv]) continue;
        visited[curv] = true;

        for(Node *node = adj[curv]->next; node != NULL; node = node->next){
            int nv = node->vertex;
            int nd = node->dis;
            if(d[nv] > d[curv] + nd){
                d[nv] = d[curv] + nd;
                Node *new = (Node*)malloc(sizeof(Node));
                new->vertex = nv;
                new->dis = d[nv];
                insert(new);
            }
        }
    }
}

int main(void){
    for(int i = 0; i < 16000; i++){
        adj[i] = (Node*)malloc(sizeof(Node));
        adj[i]->next = NULL;
    }

    while(++TC){
        N = ReadInt();
        if(!N) break;

        for(int i = 0; i <= N * N; i++) adj[i]->next = NULL;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                map[i][j] = ReadInt();
            }
        }
        setAdj();
        dijkstra();
        printf("Problem %d: %d\n", TC, d[N * N - 1]);
    }
}