#include <iostream>
#include <cstdio>
using namespace std;
#define BUFSIZE 1 << 18
char readbuf[BUFSIZE];
int rp = BUFSIZE;
char read(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
int readInt(){
    char c;
    int ret = 0;
    while(c < '0' || c > '9') c = read();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = read();
    }
    return ret;
}

int main(void){
    int N;
    N = readInt();
    long long ans = readInt();
    while(--N) ans += readInt() - 1;
    cout << ans;
}