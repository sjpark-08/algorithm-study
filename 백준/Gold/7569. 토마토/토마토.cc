#include <cstdio>
#include <queue>
#include <iostream>
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

int M, N, H, ans;
short map[101][101][101];
short dx[6] = {0, 0, -1, 1, 0, 0};
short dy[6] = {-1, 1, 0, 0, 0, 0};
short dz[6] = {0, 0, 0, 0, -1, 1};
bool visited[101][101][101];
struct Node{
    int x, y, z, t;
    Node(int x, int y, int z, int t) : x(x), y(y), z(z), t(t) {};
};
queue<Node> q;

void bfs(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int t = q.front().t;
        q.pop();
        ans = t;
        
        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx > N - 1 || ny > M - 1 || nz > H - 1) continue;
            if(map[nz][nx][ny] == -1 || visited[nz][nx][ny]) continue;
            visited[nz][nx][ny] = true;
            q.push(Node(nx, ny, nz, t + 1));
        }
    }
}

int main(void){
    M = readInt(), N = readInt(), H = readInt();
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[k][i][j] = readInt();
                if(map[k][i][j] == 1){
                    q.push(Node(i, j, k, 0));
                    visited[k][i][j] = true;
                }
            }
        }
    }
    bfs();
    bool suc = true;
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[k][i][j] == 0 && !visited[k][i][j]){
                    suc = false;
                    break;
                }
            }
        }
    }
    if(suc) cout << ans;
    else cout << -1;
}