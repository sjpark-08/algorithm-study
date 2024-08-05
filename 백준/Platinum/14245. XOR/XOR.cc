#include <cstdio>
using namespace std;
#define BUFSIZE 1 << 20
char readbuf[BUFSIZE];
int rp = BUFSIZE;
char read(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
int readInt(){
    char c;
    int ret = 0;
    while(c < '0' || c > '9') c = read();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = read();
    }
    return ret;
}

typedef long long lnt;
int tree[2000000], lazy[2000000], arr[500001];
int N, M;

void init(int node, int start, int end){
    if(start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = start + end >> 1;
    init(node << 1, start, mid);
    init(node << 1|1, mid + 1, end);
}
void update_lazy(int node, int start, int end){
    if(!lazy[node]) return;
    tree[node] ^= lazy[node];
    if(start != end){
        lazy[node << 1] ^= lazy[node];
        lazy[node << 1|1] ^= lazy[node];
    }
    lazy[node] = 0;
}
void update_range(int node, int start, int end, int left, int right, int dif){
    update_lazy(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        tree[node] ^= dif;
        if(start != end){
            lazy[node << 1] ^= dif;
            lazy[node << 1|1] ^= dif;
        }
        return;
    }
    int mid = start + end >> 1;
    update_range(node << 1, start, mid, left, right, dif);
    update_range(node << 1|1, mid + 1, end, left, right, dif);
    // tree[node] = tree[node << 1] + tree[node << 1|1];
}
int query(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    int lsum = query(node << 1, start, mid, left, right);
    int rsum = query(node << 1|1, mid + 1, end, left, right);
    return lsum + rsum;
} 

int main(void){
    int t, a, b, c;
    N = readInt();
    for(int i = 0; i < N; i++) arr[i] = readInt();
    init(1, 0, N - 1);
    M = readInt();
    while(M--){
        t = readInt();
        if(t & 1){
            a = readInt(), b = readInt(), c = readInt();
            update_range(1, 0, N - 1, a, b, c);
        }else{
            a = readInt();
            printf("%d\n", query(1, 0, N - 1, a, a));
        }
    }
}