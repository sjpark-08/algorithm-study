#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
Query query[100002];
int arr[100002], cnt[1000001], result[100002];
int N, M, sqrtN;

int compare(const void *a, const void *b){
    Query A = *(Query*)a;
    Query B = *(Query*)b;
    if(A.left / sqrtN > B.left / sqrtN) return 1;
    if(A.left / sqrtN == B.left / sqrtN && A.right > B.right) return 1;
    return -1;
}

int main(void){
    int a, b;
    N = ReadInt();

    sqrtN = sqrt(N);
    for(int i = 1; i <= N; i++) arr[i] = ReadInt();
    M = ReadInt();
    for(int i = 0; i < M; i++){
        a = ReadInt(), b = ReadInt();

        query[i].left = a;
        query[i].right = b;
        query[i].origin = i;
    }
    qsort(query, M, sizeof(Query), compare);

    int difCnt = 0;
    int left = query[0].left;
    int right = query[0].right;
    for(int i = left; i <= right; i++){
        if(cnt[arr[i]]++ == 0) difCnt++;
    }
    result[query[0].origin] = difCnt;

    for(int i = 1; i < M; i++){
        while(left < query[i].left) if(--cnt[arr[left++]] == 0) difCnt--;
        while(left > query[i].left) if(cnt[arr[--left]]++ == 0) difCnt++;
        while(right < query[i].right) if(cnt[arr[++right]]++ == 0) difCnt++;
        while(right > query[i].right) if(--cnt[arr[right--]] == 0) difCnt--;
        result[query[i].origin] = difCnt;
    }

    for(int i = 0; i < M; i++) printf("%d\n", result[i]);
}