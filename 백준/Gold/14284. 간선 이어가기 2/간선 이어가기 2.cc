#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define BUFSIZE 1 << 17
char readbuf[BUFSIZE];
int rp = BUFSIZE;
char ReadChar(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
int ReadInt(){
    char c;
    int ret = 0;
    while(c < '0' || c > '9') c = ReadChar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
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
// vector<pair<int, int>> edge[5001]; 

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
    // N = ReadInt(), M = ReadInt();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    while(M--){
        // a = ReadInt(), b = ReadInt(), c = ReadInt();
        cin >> a >> b >> c;
        edge[a].push_back(Edge(b, c));
        edge[b].push_back(Edge(a, c));
    }
    // s = ReadInt(), t = ReadInt();
    cin >> s >> t;
    dijkstra(s);
    cout << d[t] << endl;
}