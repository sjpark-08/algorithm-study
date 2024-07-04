#include <stdio.h>
#include <stdbool.h>
#define BUFSIZE 1 << 15
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
    bool sign = false;
    while(c < '0' || c > '9'){
        if(c == '-') sign = true;
        c = ReadChar();
    }
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return sign ? -ret : ret;
}
int arr[1001];
int N, Q;
int main(void){
    int q, a, b, c, d;
    N = ReadInt(), Q = ReadInt();
    for(int i = 1; i <= N; i++) arr[i] = ReadInt();

    while(Q--){
        q = ReadInt();
        if(q & 1){
            a = ReadInt(), b = ReadInt();
            long long sum = 0;
            for(int i = a; i <= b; i++) sum += arr[i];
            printf("%lld\n", sum);
            int tmp = arr[a];
            arr[a] = arr[b];
            arr[b] = tmp;
        }else{
            a = ReadInt(), b = ReadInt();
            c = ReadInt(), d = ReadInt();
            long long sum1 = 0;
            for(int i = a; i <= b; i++) sum1 += arr[i];
            long long sum2 = 0;
            for(int i = c; i <= d; i++) sum2 += arr[i];
            printf("%lld\n", sum1 - sum2);
        }
    }
}