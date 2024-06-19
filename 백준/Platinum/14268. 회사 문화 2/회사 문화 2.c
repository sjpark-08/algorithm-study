#include <stdio.h>
#include <stdlib.h>
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
    while(c < '0') c = ReadChar();
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

typedef long long lnt;
typedef struct _Node{
    int vertex;
    struct _Node *next;
}Node;

Node *adj[100001];
lnt tree[300001], lazy[300001];
int s[100001], e[100001];
int N, M, cnt;

void Insert(Node *head, int v){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = head->next;
    head->next = newNode;
}

void dfs(int x){
    s[x] = ++cnt;
    for(Node *node = adj[x]->next; node != NULL; node = node->next){
        int nxt = node->vertex;
        dfs(nxt);
    }
    e[x] = cnt;
}

void update_lazy(int node, int start, int end){
    if(!lazy[node]) return;
    tree[node] += (end - start + 1) * lazy[node];
    if(start != end){
        lazy[node << 1] += lazy[node];
        lazy[node << 1|1] += lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, int dif){
    update_lazy(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        tree[node] += (end - start + 1) * dif;
        if(start != end){
            lazy[node << 1] += dif;
            lazy[node << 1|1] += dif;
        }
        return;
    }
    int mid = start + end >> 1;
    update_range(node << 1, start, mid, left, right, dif);
    update_range(node << 1|1, mid + 1, end, left, right, dif);
    tree[node] = tree[node << 1] + tree[node << 1|1];
}

lnt query(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    lnt lsum = query(node << 1, start, mid, left, right);
    lnt rsum = query(node << 1|1, mid + 1, end, left, right);
    return lsum + rsum;
}

int main(void){
    int up, q, a, w;
    N = ReadInt(), M = ReadInt();
    for(int i = 0; i <= N; i++){
        adj[i] = (Node*)malloc(sizeof(Node));
        adj[i]->next = NULL;
    }

    ReadInt(); // 1st node
    for(int i = 2; i <= N; i++){
        up = ReadInt();
        Insert(adj[up], i);
    }    
    dfs(1);

    while(M--){
        q = ReadInt();
        if(q & 1){
            a = ReadInt(), w = ReadInt();
            update_range(1, 1, N, s[a], e[a], w);
        }else{
            a = ReadInt();
            printf("%lld\n", query(1, 1, N, s[a], s[a]));
        }
    }
}