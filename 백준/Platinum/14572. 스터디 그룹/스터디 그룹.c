#include <stdio.h>
#include <stdlib.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
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
    int level;
    int knows[31];
    int kidx;
}Student;

Student stu[100001];
int check[31];
int N, K, D;

int compare(const void *a, const void *b){
    Student A = *(Student*)a;
    Student B = *(Student*)b;
    if(A.level > B.level) return 1;
    return -1;
}

int calc(int start, int end){
    int cnt1 = 0, cnt2 = 0;
    int n = end - start + 1;
    for(int i = 1; i <= K; i++){
        if(check[i] != 0) cnt2++;
        if(check[i] == n) cnt1++;
    }
    return (cnt2 - cnt1) * n;
}

int main(void){
    int M, d, algo;
    // scanf("%d %d %d", &N, &K, &D);
    N = ReadInt(), K = ReadInt(), D = ReadInt();
    for(int i = 0; i < N; i++){
        // scanf("%d %d", &M, &d);
        M = ReadInt(), d = ReadInt();
        stu[i].level = d;
        for(int k = 0; k < M; k++){
            // scanf("%d", &algo);
            algo = ReadInt();
            stu[i].knows[k] = algo; 
        }
        stu[i].kidx = M;
    }
    qsort(stu, N, sizeof(Student), compare);
    int ans = 0;
    int left = 0, right = 0;
    while(left < N && right < N){
        if(stu[right].level - stu[left].level <= D){
            for(int i = 0; i < stu[right].kidx; i++){
                check[stu[right].knows[i]]++;
            }
            int res = calc(left, right);
            ans = Max(ans, res);
            right++;
        }else{
            for(int i = 0; i < stu[left].kidx; i++){
                check[stu[left].knows[i]]--;
            }
            left++;
        }
    }
    printf("%d\n", ans);
}