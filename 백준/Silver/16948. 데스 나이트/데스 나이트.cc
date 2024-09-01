#include <iostream>
#include <queue>
using namespace std;

bool visited[201][201];
int N, srcX, srcY, destX, destY;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

int bfs(){
    queue<pair<pair<int, int>, int>> q;
    visited[srcX][srcY] = true;
    q.push({{srcX, srcY}, 0});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        if(x == destX && y == destY) return t;
        q.pop();
        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1 || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, t + 1});
        }
    }
    return -1;
}

int main(void){
    cin >> N;
    cin >> srcX >> srcY;
    cin >> destX >> destY;
    cout << bfs();
}