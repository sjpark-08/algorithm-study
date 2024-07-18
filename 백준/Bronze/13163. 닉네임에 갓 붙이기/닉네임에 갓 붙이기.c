#include <stdio.h>
#define BUFSIZE 1 << 14
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

int main(void){
    int N;
    char c;
    char str[201];
    str[0] = 'g', str[1] = 'o', str[2] = 'd';
    N = ReadInt();
    while(N--){
        while(c != ' ') c = ReadChar();
        int idx = 3;
        while(c != '\n'){
            c = ReadChar();
            if(c == ' ') continue;
            str[idx++] = c;
        }
        str[idx] = '\0';
        c = ReadChar();
        printf("%s", str);
    }
}