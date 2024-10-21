#include <iostream>
#include <cstdio>
#include <vector>
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

int N, M, A, B, X, ans;
vector<int> edge[100001];
bool visited[100001];

void dfs(int now){
    for(auto next : edge[now]){
        if(visited[next]) continue;
        ans++;
        visited[next] = true;
        dfs(next);
    }
}

int main(void){
    N = readInt(), M = readInt();
    while(M--){
        A = readInt(), B = readInt();
        edge[B].push_back(A);
    }
    X = readInt();
    dfs(X);

    cout << ans;
}