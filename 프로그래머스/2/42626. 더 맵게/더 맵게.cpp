#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long> q;
    for(auto s : scoville){
        q.push(-s);
    }
    while(-q.top() < K){
        if(q.size() == 1) return -1;
        long long s1 = -q.top(); q.pop();
        long long s2 = -q.top(); q.pop();
        long long news = s1 + s2 * 2;
        q.push(-news);
        answer++;
    }
    
    return answer;
}