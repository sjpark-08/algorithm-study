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
    bool sign = false;
    while(c < '0'){
        if(c == '-') sign = true;
        c = ReadChar();
    }
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return sign ? -ret : ret;
}

typedef struct _Node{
    int vertex;
    struct _Node *next;
}Node;
Node *adj[500001];
long long tree[1500001], lazy[1500001];
int s[500001], e[500001], arr[500001], tmp[500001];
int N, M, cnt;

void dfs(int x){
    s[x] = ++cnt;
    for(Node *node = adj[x]->next; node != NULL; node = node->next){
        int nx = node->vertex;
        dfs(nx);
    }
    e[x] = cnt;
}

void Insert(Node *head, int v){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = head->next;
    head->next = newNode;
}

long long init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = start + end >> 1;
    return tree[node] = init(node << 1, start, mid) + init(node << 1|1, mid + 1, end);
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
long long query(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    long long lsum = query(node << 1, start, mid, left, right);
    long long rsum = query(node << 1|1, mid + 1, end, left, right);
    return lsum + rsum;
}

int main(void){
    int a, x, up;
    char opcode;

    N = ReadInt(), M = ReadInt();
    for(int i = 0; i <= N; i++){
        adj[i] = (Node*)malloc(sizeof(Node));
        adj[i]->next = NULL;
    }
    tmp[1] = ReadInt(); // 1st node
    for(int i = 2; i <= N; i++){
        tmp[i] = ReadInt();
        up = ReadInt();
        Insert(adj[up], i);
    }
    dfs(1);
    for(int i = 1; i <= N; i++) arr[s[i]] = tmp[i];
    // for(int i = 1; i <= N; i++) printf("%d %d\n", s[i], e[i]);
    // for(int i = 1; i <= N; i++) printf("%d\n", arr[s[i]]);
    init(1, 1, N);

    while(M--){
        opcode = ReadChar();
        if(opcode == 'p'){
            a = ReadInt(), x = ReadInt();
            update_range(1, 1, N, s[a], e[a], x);
            update_range(1, 1, N, s[a], s[a], -x);
        }else{
            a = ReadInt();
            printf("%lld\n", query(1, 1, N, s[a], s[a]));
        }
    }
}