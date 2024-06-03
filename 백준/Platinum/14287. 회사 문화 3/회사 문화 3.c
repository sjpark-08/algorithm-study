#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1 << 19
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
Node *adj[100001];
int n, m, cnt;
int s[100001], e[100001];
int tree[400001];

void Insert(Node *head, int v){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = head->next;
    head->next = newNode;
}

void dfs(int x){
    s[x] = ++cnt;
    for(Node *node = adj[x]->next; node != NULL; node = node->next){
        int nx = node->vertex;
        dfs(nx);
    }
    e[x] = cnt;
}
int query(int l, int r){
    int ret = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) ret += tree[l++];
        if(r & 1) ret += tree[--r];
    }
    return ret;
}
void update(int i, int dif){
    for(tree[i += n] += dif; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1]; 
}

int main(void){
    int q, a, b, up;
    n = ReadInt(), m = ReadInt();
    for(int i = 0; i <= n; i++){
        adj[i] = (Node*)malloc(sizeof(Node));
        adj[i]->next = NULL;
    }
    ReadInt();
    for(int i = 2; i <= n; i++){
        up = ReadInt();
        Insert(adj[up], i);
    }
    dfs(1);
    while(m--){
        q = ReadInt();
        if(q & 1){
            a = ReadInt(), b = ReadInt();
            update(s[a], b);
        }else{
            a = ReadInt();
            printf("%d\n", query(s[a], e[a] + 1));
        }
    }
}