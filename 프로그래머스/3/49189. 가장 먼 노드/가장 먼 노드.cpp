#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> edges[20001];
int d[20001];
void dijkstra(){
    priority_queue<pair<int, int>> q;
    for(int i = 0; i <= 20000; i++) d[i] = 0x7f7f7f7f;
    d[1] = 0;
    q.push({0, 1});
    
    while(!q.empty()){
        int cost = -q.top().first;
        int now = q.top().second;
        q.pop();
        for(int i = 0; i < edges[now].size(); i++){
            int nCost = 1;
            int next = edges[now][i];
            if(d[next] > cost + nCost){
                d[next] = cost + nCost;
                q.push({-d[next], next});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++){
        int a = edge[i][0];
        int b = edge[i][1];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dijkstra();
    int maxval = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == 0x7f7f7f7f) continue;
        if(maxval < d[i]){
            maxval = d[i];
            answer = 0;
        }
        if(maxval == d[i]) answer++;
    }
    return answer;
}