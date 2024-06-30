#include <stdio.h>
#define BUFSIZE 1 << 16
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
#define Max(x, y) ((x) > (y) ? (x) : (y))

int main(void){
    int N;
    N = ReadInt();
    long long sum = 0;
    int max = 0;
    int num;
    for(int i = 0; i < N; i++){
        num = ReadInt();
        max = Max(max, num);
        sum += num;
    }
    if(N == 1 && sum == 1) printf("Happy");
    else if(max <= sum - max) printf("Happy");
    else printf("Unhappy");
}