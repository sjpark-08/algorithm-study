#include <iostream>
using namespace std;

bool visited[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void){
    int C, R, K;
    cin >> C >> R >> K;
    if(C * R < K){
        cout << 0;
        return 0;
    }
    int direction = 0;
    int cnt = 1, x = 1, y = 1;
    while(true){
        visited[x][y] = true;
        if(cnt == K) break;
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(nx < 1 || ny < 1 || nx > C || ny > R || visited[nx][ny]){
            direction = (direction + 1) % 4;
            nx = x + dx[direction];
            ny = y + dy[direction];
        }
        cnt++;
        x = nx, y = ny;
    }
    cout << x << ' ' << y;
}