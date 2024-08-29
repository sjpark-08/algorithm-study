#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> edge[201];
bool visited[201];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto next : edge[now]){
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            if(i == j) continue;
            if(computers[i][j]) edge[i].push_back(j);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        bfs(i);
        answer++;
    }
    
    return answer;
}