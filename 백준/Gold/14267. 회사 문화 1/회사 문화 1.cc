#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define BUFSIZE 1 << 18
char readbuf[BUFSIZE], writebuf[BUFSIZE];
int rp = BUFSIZE, wp = 0;
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
void writeInt(int n){
    int tmp = n, cnt = 0;
    while(tmp > 0){
        tmp /= 10;
        cnt++;
    }
    if(n == 0) cnt = 1;
    if(wp + cnt + 1 >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    writebuf[wp + cnt] = ' ';
    int len = cnt;
    if(n == 0) writebuf[wp + --cnt] = '0';
    while(n > 0){
        --cnt;
        writebuf[wp + cnt] = n % 10 + 48;
        n /= 10;
    }
    wp += len + 1;
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
    N = readInt(), M = readInt();
    readInt();
    for(int i = 2; i <= N; i++){
        int up = readInt();
        edge[up].push_back(i);
    }
    for(int i = 0; i < M; i++){
        a = readInt(), b = readInt();
        dp[a] += b;
    }
    update(1);
    for(int i = 1; i <= N; i++) writeInt(dp[i]);
    fwrite(writebuf, 1, wp, stdout);
}