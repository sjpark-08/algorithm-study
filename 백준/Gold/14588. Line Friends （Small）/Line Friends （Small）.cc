#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Line{
    int idx, l, r;
    Line(int idx, int l, int r) : idx(idx), l(l), r(r) {}
    bool operator < (const Line &line) const {
        return l < line.l;
    }
};

int N, Q, L, R;
vector<Line> lines;
vector<int> edge[301];

int bfs(int src, int dest){
    bool visited[301] = {false, };
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;

    while(!q.empty()){
        int now = q.front().first;
        int d = q.front().second;
        q.pop();
        if(now == dest) return d;
        for(auto next : edge[now]){
            if(visited[next]) continue;
            visited[next] = true;
            q.push({next, d + 1});
        }
    }
    return -1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> L >> R;
        lines.push_back(Line(i, L, R));
    }
    sort(lines.begin(), lines.end());
    // for(auto line : lines) cout << line.idx << ' ' << line.l << ' ' << line.r << '\n';
    for(int i = 0; i < lines.size(); i++){
        for(int j = i + 1; j < lines.size(); j++){
            if(lines[i].r < lines[j].l) break;
            edge[lines[i].idx].push_back(lines[j].idx);
            edge[lines[j].idx].push_back(lines[i].idx);
        }
    }

    int a, b;
    cin >> Q;
    while(Q--){
        cin >> a >> b;
        cout << bfs(a, b) << '\n';
    }
}