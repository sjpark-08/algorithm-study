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
int query(int start, int end, int left, int right, int node){
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return query(start, mid, left, right, node << 1) + query(mid + 1, end, left, right, node << 1|1);
}
void update(int start, int end, int index, int dif, int node){
    if(index < start || end < index) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = start + end >> 1;
    update(start, mid, index, dif, node << 1);
    update(mid + 1, end, index, dif, node << 1|1);
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
    //for(int i = 1; i <= n; i++) printf("%d ", s[i]); printf("\n");
    //for(int i = 1; i <= n; i++) printf("%d ", e[i]); printf("\n");
    while(m--){
        q = ReadInt();
        if(q & 1){
            a = ReadInt(), b = ReadInt();
            update(1, n, s[a], b, 1);
        }else{
            a = ReadInt();
            printf("%d\n", query(1, n, s[a], e[a], 1));
        }
    }
}