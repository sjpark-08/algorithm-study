#include <iostream>
using namespace std;

int ans = 10000;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int board[5][5];
bool visited[5][5];

void go(int depth, int x, int y, int cnt){
    if(board[x][y] == 1) cnt++;
    if(cnt == 3){
        ans = min(ans, depth);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > 4 || ny > 4 || visited[nx][ny] || board[nx][ny] == -1) continue;
        visited[nx][ny] = true;
        go(depth + 1, nx, ny, cnt);
        visited[nx][ny] = false;
    }
    return;
}

int main(void){
    int r, c;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> board[i][j];
        }
    }
    cin >> r >> c;
    visited[r][c] = true;
    go(0, r, c, 0);
    cout << (ans == 10000 ? -1 : ans);
}