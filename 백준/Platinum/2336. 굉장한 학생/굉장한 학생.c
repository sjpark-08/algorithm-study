#include <stdio.h>
#include <stdlib.h>
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define INF 0x7f7f7f7f
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

typedef struct{
    int first;
    int second;
    int third;
}Rank;
Rank rank[500003];
int tree[1000004];
int N;

// int compare(const void *a, const void *b){
//     return (*(Rank*)a).first < (*(Rank*)b).first;
// }
int compare(const void *a, const void *b){
    Rank A = *(Rank*)a;
    Rank B = *(Rank*)b;
    if(A.first > B.first) return 1;
    else if(A.first < B.first) return -1;
    else return 0;
}

void init(){
    for(int i = N - 1; i > 0; i--) tree[i] = Min(tree[i << 1], tree[i << 1|1]);
}
void update(int i, int dif){
    for(tree[i += N] = dif; i > 1; i >>= 1) tree[i >> 1] = Min(tree[i], tree[i ^ 1]);
}
int query(int l, int r){
    int res = INF;
    for(l += N, r += N; l < r; l >>= 1, r >>= 1){
        if(l & 1){
            res = Min(res, tree[l]);
            l++;
        }
        if(r & 1){
            --r;
            res = Min(res, tree[r]);
        }
    }
    return res;
}

// [1, 2번 등수] 존재 O or X, 구간 최소값 > 3번 등수 = 굉장하다
int main(void){
    N = ReadInt();
    for(int i = 1; i <= N; i++) rank[ReadInt()].first = i;
    for(int i = 1; i <= N; i++) rank[ReadInt()].second = i;
    for(int i = 1; i <= N; i++) rank[ReadInt()].third = i;
    for(int i = N; i < 2 * N; i++) tree[i] = INF;
    init();
    qsort(rank, N + 1, sizeof(Rank), compare);
    int ans = 0;
    for(int i = 1; i <= N; i++){
        int res = query(1, rank[i].second);
        if(res > rank[i].third) ans++;
        update(rank[i].second, rank[i].third);
    }
    printf("%d\n", ans);
}