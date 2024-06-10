#include <stdio.h>
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

long long tree[300002], lazy[300002];
int arr[100002], difference[100002]; // 인접 원소간의 차이값
int N, Q, L, R, X;

long long init(int node, int start, int end){
    if(start == end) return tree[node] = difference[start];
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
    int q;
    N = ReadInt();
    for(int i = 1; i <= N; i++){
        arr[i] = ReadInt();
        difference[i] = arr[i] - arr[i - 1];
    }
    init(1, 1, N);
    Q = ReadInt();
    while(Q--){
        q = ReadInt();
        if(q & 1){
            L = ReadInt(), R = ReadInt();
            update_range(1, 1, N, L, R, 1);
            update_range(1, 1, N, R + 1, R + 1, -(R - L + 1));
        }else{
            X = ReadInt();
            printf("%lld\n", query(1, 1, N, 1, X));
        }
    }
    
}