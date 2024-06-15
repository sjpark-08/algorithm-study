#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
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
Query query[100002];
int arr[100002], cnt[100002], ccnt[100002], result[100002];
int N, M, sqrtN;

int compare(const void *a, const void *b){
    Query A = *(Query*)a;
    Query B = *(Query*)b;
    if(A.left / sqrtN > B.left / sqrtN) return 1;
    if(A.left / sqrtN == B.left / sqrtN && A.right > B.right) return 1;
    return -1;
}

int main(void){
    int l, r;
    N = ReadInt();
    for(int i = 1; i <= N; i++) arr[i] = ReadInt();
    sqrtN = sqrt(N);

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
    int ans = 0;
    for(int i = left; i <= right; i++){
        int now = arr[i];
        ccnt[cnt[now]]--;
        cnt[now]++;
        ans = Max(ans, cnt[now]);
        ccnt[cnt[now]]++;
    }
    result[query[0].origin] = ans;

    for(int i = 1; i < M; i++){
        while(left < query[i].left) {
            // --cnt[arr[left++]];
            int now = arr[left];
            ccnt[cnt[now]]--;
            if(ccnt[cnt[now]] == 0 && cnt[now] == ans) ans--;
            cnt[now]--;
            ccnt[cnt[now]]++;
            left++;
        }
        while(left > query[i].left) {
            // cnt[arr[--left]]++;
            --left;
            int now = arr[left];
            ccnt[cnt[now]]--;
            cnt[now]++;
            ccnt[cnt[now]]++;
            ans = Max(ans, cnt[now]);
        }
        while(right < query[i].right) {
            // cnt[arr[++right]]++;
            ++right;
            int now = arr[right];
            ccnt[cnt[now]]--;
            cnt[now]++;
            ccnt[cnt[now]]++;
            ans = Max(ans, cnt[now]);
        }
        while(right > query[i].right) {
            // --cnt[arr[right--]];
            int now = arr[right];
            ccnt[cnt[now]]--;
            if(ccnt[cnt[now]] == 0 && cnt[now] == ans) ans--;
            cnt[now]--;
            ccnt[cnt[now]]++;
            right--;
        }
        result[query[i].origin] = ans;
    }

    for(int i = 0; i < M; i++) printf("%d\n", result[i]);
}                                                                                                                                       