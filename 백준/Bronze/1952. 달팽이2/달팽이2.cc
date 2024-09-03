#include <iostream>
using namespace std;

int M, N;
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void){
    cin >> M >> N;
    int ans = 0;
    int x = 0, y = 0, d = 0;
    while(true){
        visited[x][y] = true;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1 || visited[nx][ny]){
            d = (d + 1) % 4;
            int xx = x + dx[d];
            int yy = y + dy[d];
            x = xx, y = yy;
            if(xx < 0 || yy < 0 || xx > M - 1 || yy > N - 1 || visited[xx][yy]) break;
            ans++;
            continue;
        }
        x = nx, y = ny;
    }
    cout << ans;
}