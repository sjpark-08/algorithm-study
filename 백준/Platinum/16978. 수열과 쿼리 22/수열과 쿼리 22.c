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
long long tree[200001];
long long result[100001];
// int arr[100001];
int N, M;

void init(){
    for(int i = N - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1|1];
}
void update(int i, int val){
    for(tree[i += N] = val; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
}
long long query(int l, int r){
    long long res = 0;
    for(l += N, r += N; l < r; l >>= 1, r >>= 1){
        if(l & 1) res += tree[l++];
        if(r & 1) res += tree[--r];
    }
    return res;
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
    for(int i = N; i < 2 * N; i++) tree[i] = ReadInt();
    init();

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
        result[sQuery[i].origin] = query(sQuery[i].left - 1, sQuery[i].right);
        curSIdx++;
    }

    for(int i = curSIdx; i < sidx; i++){
        while(curUIdx + 1 <= sQuery[i].k){
            int idx = uQuery[curUIdx].i;
            int val = uQuery[curUIdx].v;
            // arr[idx] = val;
            update(idx - 1, val);
            curUIdx++;
        }
        result[sQuery[i].origin] = query(sQuery[i].left - 1, sQuery[i].right);
    }
    
    for(int i = 0; i < sidx; i++) printf("%lld\n", result[i]);
}