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
    char c, ret = read() & 0xf;
    while((c = read()) & 0x10) ret = ret * 10 + (c & 0xf);
    return ret;
}

vector<int> edge[300001];
int cnt[300001], parent[300001];
bool visited[300001];
long long ans;
int N;

// nC2 - xC2
long long calc(int k){
    int X = N - k;
    long long ret = (long long)N * (N - 1) / 2 - (long long)X * (X - 1) / 2;
    return ret;
}

void dfs(int now){
    cnt[now] = 1;
    visited[now] = true;
    for(auto next : edge[now]){
        if(visited[next]) continue;
        parent[next] = now;
        dfs(next);
    }
    if(now == 1) return;
    cnt[parent[now]] += cnt[now];
    ans += calc(cnt[now]);
}

int main(void){
    int a, b;
    N = readInt();
    for(int i = 0; i < N - 1; i++){
        a = readInt(), b = readInt();
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1);
    cout << ans << '\n';
}