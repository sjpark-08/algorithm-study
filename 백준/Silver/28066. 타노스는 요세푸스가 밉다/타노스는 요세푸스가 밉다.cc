#include <iostream>
#include <queue>
using namespace std;

int N, K;

int main(void){
    cin >> N >> K;
    queue<int> q;
    for(int i = 1; i <= N; i++) q.push(i);
    int cur = q.front();
    q.pop();
    q.push(cur);
    while(q.size() > K){
        for(int i = 0; i < K - 1; i++) q.pop();
        cur = q.front();
        q.pop();
        q.push(cur);
    }
    cout << cur;
}