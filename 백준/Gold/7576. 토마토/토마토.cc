#include <queue>
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
    bool sign = false;
    while(c < '0' || c > '9'){
        if(c == '-') sign = true;
        c = read();
    }
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = read();
    }
    return sign ? -ret : ret;
}

int M, N, ans;
short map[1001][1001];
short dx[4] = {0, 0, -1, 1};
short dy[4] = {-1, 1, 0, 0};
bool visited[1001][1001];
queue<pair<pair<int, int>, int>> q;

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();
        ans = t;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1) continue;
            if(map[nx][ny] == -1 || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, t + 1});
        }
    }
}

int main(void){
    M = readInt(), N = readInt();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = readInt();
            if(map[i][j] == 1){
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }
    bfs();
    bool suc = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0 && !visited[i][j]){
                suc = false;
                break;
            }
        }
    }
    if(suc) cout << ans;
    else cout << -1;
}