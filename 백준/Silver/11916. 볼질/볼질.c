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

// ball : 1, dead : 2, fire : 3
int base[4];
int N, ball, ballCnt, ans;

int main(void){
    N = ReadInt();
    for(int i = 0; i < N; i++){
        ball = ReadInt();
        if(ball == 1) ballCnt++;
        else if(ball == 2) ballCnt = 4;
        else{
            if(base[3]){
                ans++;
                base[3] = 0;
            }
            if(base[2]){
                base[3] = 1;
                base[2] = 0;
            }
            if(base[1]){
                base[2] = 1;
                base[1] = 0;
            }
            ballCnt++;
        }
        if(ballCnt == 4){
            if(base[3] && base[2] && base[1]) ans++;
            else if(base[2] && base[1]) base[3] = 1;
            else if(base[1]) base[2] = 1;
            else base[1] = 1;
            ballCnt = 0;
        }
    }
    printf("%d\n", ans);
}