#include <stdio.h>
#include <stdlib.h>
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

typedef struct{
    int start;
    int end;
}Time;
Time time[100001];

int compare(const void *a, const void *b){
    Time A = *(Time*)a;
    Time B = *(Time*)b;

    if(A.end > B.end) return 1;
    if(A.end == B.end && A.start > B.start) return 1;
    return -1;
}

int main(void){
    int N;
    N = ReadInt();
    for(int i = 0; i < N; i++){
        time[i].start = ReadInt();
        time[i].end = ReadInt();
    }
    qsort(time, N, sizeof(Time), compare);

    int ans = 0;
    int prev;
    for(int i = 0; i < N; i++){
        if(i == 0){
            prev = time[i].end;
            ans++;
            continue;
        }
        if(prev > time[i].start) continue;
        prev = time[i].end;
        ans++;
    }
    printf("%d\n", ans);
}
