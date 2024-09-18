#include <iostream>
#include <cstdio>
#include <queue>
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
    priority_queue<int> q;
    int N, Hc, T, H;
    N = readInt(), Hc = readInt(), T = readInt();
    for(int i = 0; i < N; i++){
        H = readInt();
        q.push(H);
    }
    int cnt = 0;
    while(T--){
        if(q.top() < Hc || q.top() == 1) break;
        int tmp = q.top();
        q.pop();
        q.push(tmp >> 1);
        cnt++;
    }
    if(q.top() >= Hc) cout << "NO" << '\n' << q.top() << '\n';
    else cout << "YES" << '\n' << cnt << '\n';
}