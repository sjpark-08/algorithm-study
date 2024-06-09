#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int vertex;
    struct _Node *next;
}Node;
Node *adj[100001];
long long tree[300001], lazy[300001];
int s[100001], e[100001];
int N, M, cnt;

void Insert(Node *head, int v){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = head->next;
    head->next = newNode;
}
void dfs(int x, int p){
    s[x] = ++cnt;
    for(Node *node = adj[x]->next; node != NULL; node = node->next){
        int nx = node->vertex;
        if(nx != p)
            dfs(nx, x);
    }
    e[x] = cnt;
}

void update_lazy(int node, int start, int end){
    if(lazy[node] == 0) return;
    tree[node] += (end - start + 1) * lazy[node];
    if(start != end){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, int dif){
    update_lazy(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        tree[node] += (end - start + 1) * dif;
        if(start != end){
            lazy[node * 2] += dif;
            lazy[node * 2 + 1] += dif;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, dif);
    update_range(node * 2 + 1, mid + 1, end, left, right, dif);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main(void){
    int up, q, a, b;
    scanf("%d %d", &N, &M);
    for(int i = 0; i <= N; i++){
        adj[i] =(Node*)malloc(sizeof(Node));
        adj[i]->next = NULL;
    }
    for(int i = 1; i <= N; i++){
        scanf("%d", &up);
        if(up == -1) continue;
        Insert(adj[up], i);
        Insert(adj[i], up);
    }
    dfs(1, -1);

    while(M--){
        scanf("%d", &q);
        if(q & 1){
            scanf("%d %d", &a, &b);
            update_range(1, 1, N, s[a], e[a], b);
        }else{
            scanf(" %d", &a);
            long long res = query(1, 1, N, s[a], s[a]);
            printf("%lld\n", res);
        }
    }
}