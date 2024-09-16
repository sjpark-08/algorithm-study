#include <iostream>
#include <queue>
using namespace std;

int N, M, srcX, srcY, destX, destY;
string map[301];
bool visited[301][301];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(){
    deque<pair<pair<int, int>, int>> q;
    q.push_front({{srcX, srcY}, 0});
    visited[srcX][srcY] = true;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop_front();
        if(x == destX && y == destY) return t;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1 || visited[nx][ny]) continue;
            if(map[nx][ny] == '0') q.push_front({{nx, ny}, t});
            else q.push_back({{nx, ny}, t + 1});
            visited[nx][ny] = true;
        }
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    cin >> srcX >> srcY >> destX >> destY;
    srcX--, srcY--, destX--, destY--;
    for(int i = 0; i < N; i++) cin >> map[i];
    cout << bfs();
}