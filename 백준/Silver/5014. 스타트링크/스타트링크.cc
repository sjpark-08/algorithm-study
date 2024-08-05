#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool visited[1000001];
int d[1000001];
int F, S, G, U, D;

void bfs(int src){
    queue<int> q;
    q.push(src);
    d[src] = 0;
    visited[src] = true;

    while(!q.empty()){
        int now = q.front();
        if(now == G) return;
        q.pop();
        if(now + U <= F && !visited[now + U]){
            q.push(now + U);
            d[now + U] = d[now] + 1;
            visited[now + U] = true;
        }
        if(now - D >= 1 && !visited[now - D]){
            q.push(now - D);
            d[now - D] = d[now] + 1;
            visited[now - D] = true;
        }
    }
}

int main(void){
    cin >> F >> S >> G >> U >> D;
    memset(d, -1, sizeof(d));
    bfs(S);
    if(d[G] == - 1) cout << "use the stairs";
    else cout << d[G];
}