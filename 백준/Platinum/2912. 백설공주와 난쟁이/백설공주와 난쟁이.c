#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
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
    while(c >= '0') {
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

typedef struct{
    int origin;
    int left, right;
}Query;
Query query[10002];
int arr[300002], cnt[10002], result[10002];
int N, M, C, sqrtN;

int compare(const void *a, const void *b){
    Query A = *(Query*)a;
    Query B = *(Query*)b;
    if(A.left / sqrtN > B.left / sqrtN) return 1;
    if(A.left / sqrtN == B.left / sqrtN && A.right > B.right) return 1;
    return -1;
}

int main(void){
    int l, r;
    N = ReadInt(), C = ReadInt();
    for(int i = 1; i <= N; i++) arr[i] = ReadInt();
    sqrtN = sqrt(N);
    memset(result, -1, sizeof(result));

    M = ReadInt();
    for(int i = 0; i < M; i++){
        l = ReadInt(), r = ReadInt();
        query[i].left = l;
        query[i].right = r;
        query[i].origin = i;
    }
    qsort(query, M, sizeof(Query), compare);

    // first query
    int left = query[0].left;
    int right = query[0].right;
    for(int i = left; i <= right; i++) cnt[arr[i]]++;
    for(int i = 1; i <= C; i++){
        if(cnt[i] > right - left + 1 >> 1){
            result[query[0].origin] = i;
            break;
        }
    }
    
    for(int i = 1; i < M; i++){
        while(left < query[i].left) --cnt[arr[left++]];
        while(left > query[i].left) cnt[arr[--left]]++;
        while(right < query[i].right) cnt[arr[++right]]++;
        while(right > query[i].right) --cnt[arr[right--]];

        for(int k = 1; k <= C; k++){
            if(cnt[k] > right - left + 1 >> 1){
                result[query[i].origin] = k;
                break;
            }
        }
    }

    for(int i = 0; i < M; i++){
        if(result[i] == -1) printf("no\n");
        else printf("yes %d\n", result[i]);
    }
}                                                                                                                                       