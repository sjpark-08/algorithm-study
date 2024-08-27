#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool map[101][101];
bool visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M, ans;

void bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(x == N - 1 && y == M - 1){
            ans = d;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1) continue;
            if(visited[nx][ny] || !map[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, d + 1});
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            map[i][j] = str[j] == '1' ? true : false;
        }
    }
    bfs();
    cout << ans;
}