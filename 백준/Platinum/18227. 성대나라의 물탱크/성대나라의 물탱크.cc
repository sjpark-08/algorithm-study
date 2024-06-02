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
long long tree[800001];
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

void update(int start, int end, int node, int index){
    if(index < start || end < index) return;
    tree[node] += 1;
    if(start == end) return;
    int mid = start + end >> 1;
    update(start, mid, node << 1, index);
    update(mid + 1, end, node << 1|1, index);
}
long long query(int start, int end, int left, int right, int node){
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return query(start, mid, left, right, node << 1) + query(mid + 1, end, left, right, node << 1|1);
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
        if(q & 1) update(1, N, 1, s[a]);
        else{
            long long ans = query(1, N, s[a], e[a], 1) * d[a];
            printf("%lld\n", ans);
        }
    }
}