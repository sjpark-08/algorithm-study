#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFSIZE 1 << 20
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
    while(c < '0') c = ReadChar();
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}
typedef struct _Node{
    int vertex;
    struct _Node *next;
}Node;
Node *adj[200001];
int s[200001], e[200001], d[200001];
int N, C, Q, cnt;
long long tree[400001];
bool visited[200001];

void Insert(Node *head, int v){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = head->next;
    head->next = newNode;
}

void dfs(int idx, int depth){
    visited[idx] = true;
    s[idx] = ++cnt;
    d[idx] = depth;
    for(Node *node = adj[idx]->next; node != NULL; node = node->next){
        int nx = node->vertex;
        if(visited[nx]) continue;
        dfs(nx, depth + 1);
    }
    e[idx] = cnt;
}

void update(int i){
    for(tree[i += N] += 1; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
}
long long query(int l, int r){
    long long res = 0;
    for(l += N, r += N; l < r; l >>= 1, r >>= 1){
        if(l & 1) res += tree[l++];
        if(r & 1) res += tree[--r];
    }
    return res;
}

int main(void){
    int a, b, q;
    N = ReadInt(), C = ReadInt();
    for(int i = 0; i <= N; i++){
        adj[i] = (Node*)malloc(sizeof(Node));
        adj[i]->next = NULL;
    }
    for(int i = 0; i < N - 1; i++){
        a = ReadInt(), b = ReadInt();
        Insert(adj[a], b);
        Insert(adj[b], a);
    }
    dfs(C, 1);
    Q = ReadInt();
    while(Q--){
        q = ReadInt(), a = ReadInt();
        if(q & 1) update(s[a]);
        else{
            long long ans = query(s[a], e[a] + 1) * d[a];
            printf("%lld\n", ans);
        }
    }
}