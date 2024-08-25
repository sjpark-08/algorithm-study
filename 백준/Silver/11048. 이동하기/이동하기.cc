#include <iostream>
#include <cstdio>
using namespace std;
#define BUFSIZE 1 << 19
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

int map[1001][1001];
int dp[1001][1001];

int main(void){
    int N, M;
    N = readInt(), M = readInt();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            map[i][j] = readInt();
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] = map[i][j] + max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    cout << dp[N][M];
}