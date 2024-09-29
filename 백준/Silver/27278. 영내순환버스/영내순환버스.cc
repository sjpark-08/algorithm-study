#include <cstdio>
#include <iostream>
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

int tsum[100001];
int N, M, t, in, out, maxt, st;

int main(void){
    N = readInt(), M = readInt();
    for(int i = 1; i <= N; i++) tsum[i] = tsum[i - 1] + readInt();
    for(int i = 0; i < M; i++){
        in = readInt(), out = readInt(), st = readInt();
        int tmp = st / tsum[N];
        int start, end;
        if(tmp * tsum[N] + tsum[in - 1] >= st) start = tmp * tsum[N] + tsum[in - 1];
        else start = (tmp + 1) * tsum[N] + tsum[in - 1];
        if(in < out) end = start + tsum[out - 1] - tsum[in - 1];
        else end = start + tsum[N] - tsum[in - 1] + tsum[out - 1];
        maxt = max(maxt, end);
    }
    cout << maxt;
}