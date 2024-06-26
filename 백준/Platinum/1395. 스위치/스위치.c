#include <stdio.h>
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
    while(c < '0' || c > '9') c = ReadChar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

int tree[300001], lazy[300001];
int N, M;

void update_lazy(int node, int start, int end){
    if(!lazy[node]) return;
    if(lazy[node] & 1) tree[node] = (end - start + 1) - tree[node];
    if(start != end){
        lazy[node << 1] += lazy[node];
        lazy[node << 1|1] += lazy[node];
    }
    lazy[node] = 0;
}
void update_range(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        tree[node] = (end - start + 1) - tree[node];
        if(start != end){
            lazy[node << 1]++;
            lazy[node << 1|1]++;
        }
        return;
    }
    int mid = start + end >> 1;
    update_range(node << 1, start, mid, left, right);
    update_range(node << 1|1, mid + 1, end, left, right);
    tree[node] = tree[node << 1] + tree[node << 1|1];
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
    int O, S, T;
    N = ReadInt(), M = ReadInt();
    while(M--){
        O = ReadInt(), S = ReadInt(), T = ReadInt();
        if(!O) update_range(1, 1, N, S, T);
        else printf("%lld\n", query(1, 1, N, S, T));
    }
}