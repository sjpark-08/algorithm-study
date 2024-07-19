#include <stdio.h>
#define BUFSIZE 1 < 18
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
    int prev = ReadInt();
    int leftInc = 0, leftDec = 0, ans = 1;
    for(int right = 1; right < N; right++){
        int cur = ReadInt();
        if(prev > cur) leftInc = right;
        if(prev < cur) leftDec = right;
        ans = Max(ans, Max(right - leftInc + 1, right - leftDec + 1));
        prev = cur;
    }
    printf("%d\n", ans);
}