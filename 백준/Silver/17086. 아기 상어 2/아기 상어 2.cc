#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool map[51][51];
int N, M, ans;

int bfs(int srcX, int srcY){
    bool visited[51][51] = {false, };
    queue<pair<pair<int, int>, int>> q;
    q.push({{srcX, srcY}, 0});

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        // if(map[x][y]) return d;
        q.pop();

        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]) return d + 1;
            visited[nx][ny] = true;
            q.push({{nx, ny}, d + 1});
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> map[i][j];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j]) continue;
            ans = max(ans, bfs(i, j));
        }
    }
    cout << ans;
}