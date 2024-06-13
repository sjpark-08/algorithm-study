#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1 << 18
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

typedef struct{
    int k; // kth query
    int left, right; // range
    int origin;
}SQuery;
typedef struct{
    int i; // A[i]
    int v; // update
}UQuery;

SQuery sQuery[100001];
UQuery uQuery[100001];
long long tree[300001];
long long result[100001];
int arr[100001];
int N, M;

long long init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = start + end >> 1;
    return tree[node] = init(node << 1, start, mid) + init(node << 1|1, mid + 1, end);
}
void update(int node, int start, int end, int index, int dif){
    if(index < start || end < index) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = start + end >> 1;
    update(node << 1, start, mid, index, dif);
    update(node << 1|1, mid + 1, end, index, dif);
}
long long query(int node, int start, int end, int left, int right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    long long lsum = query(node << 1, start, mid, left, right);
    long long rsum = query(node << 1|1, mid + 1, end, left, right);
    return lsum + rsum;
}

int compare(const void *a, const void *b){
    SQuery A = *(SQuery*)a;
    SQuery B = *(SQuery*)b;
    if(A.k > B.k) return 1;
    return -1;
}

int main(void){
    int q, i, v, j, k;
    N = ReadInt();
    for(int i = 1; i <= N; i++) arr[i] = ReadInt();
    init(1, 1, N);

    M = ReadInt();
    int sidx = 0, uidx = 0;
    while(M--){
        q = ReadInt();
        if(q & 1){
            i = ReadInt(), v = ReadInt();
            uQuery[uidx].i = i;
            uQuery[uidx].v = v;
            uidx++;
        }else{
            k = ReadInt(), i = ReadInt(), j = ReadInt();
            sQuery[sidx].k = k;
            sQuery[sidx].left = i;
            sQuery[sidx].right = j;
            sQuery[sidx].origin = sidx;
            sidx++;
        }
    }
    qsort(sQuery, sidx, sizeof(SQuery), compare);
    
    int curSIdx = 0;
    int curUIdx = 0;
    for(int i = 0; i < sidx; i++){
        if(sQuery[i].k != 0) break;
        result[sQuery[i].origin] = query(1, 1, N, sQuery[i].left, sQuery[i].right);
        curSIdx++;
    }

    for(int i = curSIdx; i < sidx; i++){
        while(curUIdx + 1 <= sQuery[i].k){
            int idx = uQuery[curUIdx].i;
            int val = uQuery[curUIdx].v;
            int dif = val - arr[idx];
            arr[idx] = val;
            update(1, 1, N, idx, dif);
            curUIdx++;
        }
        result[sQuery[i].origin] = query(1, 1, N, sQuery[i].left, sQuery[i].right);
    }
    
    for(int i = 0; i < sidx; i++) printf("%lld\n", result[i]);
}