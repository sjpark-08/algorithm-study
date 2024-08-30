#include <cstdio>
#include <vector>
#include <iostream>
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

vector<int> edge[100001];
int dp[100001];
int N, M, a, b;

void update(int now){
    for(auto next : edge[now]){
        dp[next] += dp[now];
        update(next);
    }
    return;
}

int main(void){
    // N = readInt(), M = readInt();
    cin >> N >> M;
    // readInt();
    cin >> a;
    for(int i = 2; i <= N; i++){
        // int up = readInt();
        int up;
        cin >> up;
        edge[up].push_back(i);
    }
    for(int i = 0; i < M; i++){
        // a = readInt(), b = readInt();
        cin >> a >> b;
        dp[a] += b;
    }
    update(1);
    for(int i = 1; i <= N; i++) printf("%d ", dp[i]);
}