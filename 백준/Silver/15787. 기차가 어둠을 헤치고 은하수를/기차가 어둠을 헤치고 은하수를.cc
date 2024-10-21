#include <cstdio>
#include <iostream>
#include <set>
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

int N, M, op, i, x;
int mask = 1 << 20;
int train[100001];
set<int> duplSet;

int main(void){
    N = readInt(), M = readInt();
    // 1)  or 1 << i 
    // 2)  if 1 << i, xor 1 << i
    // 3)  << 1
    // 4)  >> 1

    while(M--){
        op = readInt();
        if(op == 1){
            i = readInt(), x = readInt();
            train[i] |= (1 << --x);
        }else if(op == 2){
            i = readInt(), x = readInt();
            train[i] &= ~(1 << --x);
        }else if(op == 3){
            i = readInt();
            train[i] <<= 1;
            if(train[i] & mask) train[i] ^= mask;
        }else if(op == 4){
            i = readInt();
            train[i] >>= 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(duplSet.find(train[i]) == duplSet.end()){
            ans++;
            duplSet.insert(train[i]);
        }
    }
    cout << ans;
}