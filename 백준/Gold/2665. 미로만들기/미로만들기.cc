#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

vector<pair<int, int>> edge[2501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool visited[2501];
int d[2501];

void dijkstra(){
    memset(d, 0x7f, sizeof(d));
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 0));
    d[0] = 0;

    while(!pq.empty()){
        int now = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        for(int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i].first;
            int nCost = edge[now][i].second;
            if(d[next] > cost + nCost){
                d[next] = cost + nCost;
                pq.push(make_pair(next, -d[next]));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    char map[51][51];
    for(int i = 0; i < N; i++){
        cin >> map[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1) continue;
                if(map[nx][ny] == '1') edge[i * N + j].push_back(make_pair(nx * N + ny, 0));
                else edge[i * N + j].push_back(make_pair(nx * N + ny, 1));
            }
        }
    }
    dijkstra();
    cout << d[N * N - 1];
}