#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visited[100002];

int bfs(){
    queue<pair<int, int>> q;
    q.push({N, 0});
    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        visited[now] = true;
        q.pop();
        if(now == K) return cost;

        if(now << 1 <= 100000 && !visited[now << 1]){
            q.push({now << 1, cost + 1});
            visited[now << 1] = true;
        }
        if(now + 1 <= 100000 && !visited[now + 1]){
            q.push({now + 1, cost + 1});
            visited[now + 1] = true;
        }
        if(now - 1 >= 0 && !visited[now - 1]){
            q.push({now - 1, cost + 1});
            visited[now - 1] = true;
        }
    }
    return 0;
}

int main(void){
    cin >> N >> K;
    cout << bfs();
}