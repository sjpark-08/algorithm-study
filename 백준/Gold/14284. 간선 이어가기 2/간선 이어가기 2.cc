#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
char buf[1 << 17];

char read() {
    static int idx = 1 << 17, nidx = 1 << 17;
    if (idx == nidx) {
        nidx = fread(buf, 1, 1 << 17, stdin);
        if (!nidx) return 0;
        idx = 0;
    }
    return buf[idx++];
}
int readInt() {
    int t, r = read() & 15;
    while ((t = read()) & 16) r = r * 10 + (t & 15);
    return r;
}

using namespace std;

struct Edge{
    int vertex;
    int dis;
    Edge(int v, int d) : vertex(v), dis(d) {}

    bool operator < (const Edge e) const {
        return this->dis > e.dis;
    }
};

vector<Edge> edge[5002];

int d[5002];
bool visited[5002];
int N, M;


void dijkstra(int src){
    priority_queue<Edge> pq;
    memset(d, 0x7f, sizeof(d));
    d[src] = 0;
    pq.push(Edge(src, 0));

    while(!pq.empty()){
        int now = pq.top().vertex;
        int cost = pq.top().dis;
        pq.pop();
        if(visited[now]) continue;
        visited[now] = true;
        for(int i = 0; i < edge[now].size(); i++){
            int next = edge[now][i].vertex;
            int nCost = edge[now][i].dis;
            if(d[next] > cost + nCost){
                d[next] = cost + nCost;
                pq.push(Edge(next, d[next]));
            }
        }
    }
}

int main(void){
    int a, b, c, s, t;
    N = readInt(), M = readInt();
    // cin >> N >> M;
    while(M--){
        a = readInt(), b = readInt(), c = readInt();
        // cin >> a >> b >> c;
        edge[a].push_back(Edge(b, c));
        edge[b].push_back(Edge(a, c));
    }
    s = readInt(), t = readInt();
    // cin >> s >> t;
    dijkstra(s);
    cout << d[t] << endl;
}