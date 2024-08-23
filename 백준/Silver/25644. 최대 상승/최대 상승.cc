#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define BUFSIZE 1 << 17
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
    int N, num, ans = 0;
    int minVal = 0x7f7f7f7f;
    N = readInt();
    for(int i = 0; i < N; i++){
        num = readInt();
        ans = max(ans, num - minVal);
        minVal = min(minVal, num);
    }
    cout << ans;
}