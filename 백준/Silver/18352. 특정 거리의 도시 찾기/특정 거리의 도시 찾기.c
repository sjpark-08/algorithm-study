#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define BUFSIZE 1 << 20
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
    while(c < '0') c = ReadChar();
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}
void WriteInt(int n){
    int tmp = n, cnt = 0;
    while(tmp){
        tmp /= 10;
        cnt++;
    }
    if(wp + cnt >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    int len = cnt;
    writebuf[wp + cnt] = '\n';
    do{
        cnt--;
        writebuf[wp + cnt] = (char)(n % 10 + 48);
        n /= 10;
    }while(n);
    wp += len + 1;
}

typedef struct _Node{
    int vertex;
    int dis;
    struct _Node *next;
}Node;
Node *adj[300001], *heap[300001];
int d[300001];
int N, M, K, X, heapsize;
bool visited[300001];

void Insert(Node *head, int v, int d){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->dis = d;
    newNode->next = head->next;
    head->next = newNode;
}

void insert_minheap(Node *item){
    int i = ++heapsize;
    while(i != 1 && item->dis < heap[i >> 1]->dis){
        heap[i] = heap[i >> 1];
        i >>= 1;
    }
    heap[i] = item;
}
Node *delete_minheap(){
    Node *item = heap[1];
    Node *temp = heap[heapsize--];
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
void dijkstra(int start){
    memset(d, 0x7f, sizeof(d));
    d[start] = 0;
    Node *src = (Node*)malloc(sizeof(Node));
    src->vertex = start;
    src->dis = 0;
    insert_minheap(src);

    while(heapsize){
        Node *cur = delete_minheap();
        int curv = cur->vertex;
        if(visited[curv]) continue;
        visited[curv] = true;
        for(Node *node = adj[curv]->next; node != NULL; node = node->next){
            int nv = node->vertex;
            int nd = node->dis;
            if(d[curv] + nd < d[nv]){
                d[nv] = d[curv] + nd;
                Node *new = (Node*)malloc(sizeof(Node));
                new->dis = d[nv];
                new->vertex = nv;
                insert_minheap(new);
            }
        }
    }
}

int main(void){
    N = ReadInt(), M = ReadInt();
    K = ReadInt(), X = ReadInt();
    for(int i = 1; i <= N; i++){
        adj[i] = (Node*)malloc(sizeof(Node));
        adj[i]->next = NULL;
    }
    int a, b;
    for(int i = 0; i < M; i++){
        a = ReadInt(), b = ReadInt();
        Insert(adj[a], b, 1);
    }
    dijkstra(X);
    bool fail = true;
    for(int i = 1; i <= N; i++){
        if(d[i] == K){
            fail = false;
            //printf("%d\n", i);
            WriteInt(i);
        }
    }
    if(fail) printf("-1\n");
    fwrite(writebuf, 1, wp, stdout);
}