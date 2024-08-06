#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define BUFSIZE 1 << 15
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

int map[101][101], visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, land_num, limit;

void bfs(pair<int, int> src){
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = land_num;

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > N || visited[nx][ny]) continue;
            if(map[nx][ny] <= limit) continue;
            visited[nx][ny] = land_num;
            q.push(make_pair(nx, ny));
        }
    }
    land_num++;
}

int main(void){
    int maxN = 0, minN = 100;
    N = readInt();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){ 
            map[i][j] = readInt();
            maxN = max(maxN, map[i][j]);
            minN = min(minN, map[i][j]);
        }
    }
    int ans = 0;
    for(int i = minN - 1; i <= maxN; i++){
        land_num = 1;
        limit = i;
        memset(visited, 0, sizeof(visited));
        for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                if(map[a][b] <= limit || visited[a][b]) continue;
                bfs(make_pair(a, b));
            }
        }
        ans = max(ans, land_num - 1);
    }
    cout << ans;
}