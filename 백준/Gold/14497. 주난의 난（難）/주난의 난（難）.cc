#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int N, M, srcX, srcY, destX, destY;
vector<pair<int, int>> edge[90001];
string map[301];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int d[90001];

void dijkstra(){
    memset(d, 0x7f, sizeof(d));
    d[srcX * M + srcY] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, srcX * M + srcY});

    while(!q.empty()){
        int cost = -q.top().first;
        int now = q.top().second;
        q.pop();
        for(int i = 0; i < edge[now].size(); i++){
            int next = edge[now][i].first;
            int nCost = edge[now][i].second;
            if(d[next] > cost + nCost){
                d[next] = cost + nCost;
                q.push({-d[next], next});
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    cin >> srcX >> srcY >> destX >> destY;
    for(int i = 0; i < N; i++) cin >> map[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == '*') srcX = i, srcY = j;
            else if(map[i][j] == '#') destX = i, destY = j;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1) continue;
                if(map[nx][ny] == '1' || map[nx][ny] == '#' || map[nx][ny] == '*') 
                    edge[i * M + j].push_back({nx * M + ny, 1});
                else edge[i * M + j].push_back({nx * M + ny, 0});
            }
        }
    }
    dijkstra();
    cout << d[destX * M + destY];
}