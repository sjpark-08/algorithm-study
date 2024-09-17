#include <iostream>
#include <cstdio>
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
    int T, N;
    long long sumOfDiv[1000001] = {0,};
    for(int i = 1; i <= 1000000; i++){
        for(int j = i; j <= 1000000; j += i){
            sumOfDiv[j] += i;
        }
    }
    for(int i = 1; i <= 1000000; i++){
        sumOfDiv[i] = sumOfDiv[i] + sumOfDiv[i - 1];
    }
    T = readInt();
    while(T--){
        N = readInt();
        printf("%lld\n", sumOfDiv[N]);
    }
}