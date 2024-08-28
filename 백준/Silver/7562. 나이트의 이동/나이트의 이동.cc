#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int N, TC, srcX, srcY, destX, destY;

int bfs(){
    bool visited[301][301] = {false, };
    queue<pair<pair<int, int>, int>> q;
    q.push({{srcX, srcY}, 0});
    visited[srcX][srcY] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(x == destX && y == destY) return d;
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1 || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, d + 1});
        }
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        cin >> srcX >> srcY;
        cin >> destX >> destY;
        cout << bfs() << '\n';
    }
}