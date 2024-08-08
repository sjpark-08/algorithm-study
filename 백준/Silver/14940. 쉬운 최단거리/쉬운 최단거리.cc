#include <iostream>
#include <queue>
#include <cstring>
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
typedef pair<pair<int, int>, int> piii;
bool map[1001][1001];
int visited[1001][1001];
int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(pair<int, int> src){
    memset(visited, -1, sizeof(visited));
    queue<piii> q;
    q.push(make_pair(src, 0));

    while(!q.empty()){
        piii now = q.front();
        q.pop();
        if(visited[now.first.first][now.first.second] != -1) continue;
        visited[now.first.first][now.first.second] = now.second;

        for(int i = 0; i < 4; i++){
            int nx = now.first.first + dx[i];
            int ny = now.first.second + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || visited[nx][ny] != -1 || !map[nx][ny]) continue;
            q.push(make_pair(make_pair(nx, ny), now.second + 1));
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cout.tie(0);
    int num;
    N = readInt(), M = readInt();
    pair<int, int> src;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            num = readInt();
            if(num == 2){
                src.first = i;
                src.second = j;
            }else if(num == 1) map[i][j] = true;
        }
    }
    bfs(src);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(visited[i][j] == -1 && !map[i][j]) cout << 0 << ' ';
            else cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}