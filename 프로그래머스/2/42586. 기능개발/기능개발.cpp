#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int ans = 0;
    int curtime = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < progresses.size(); i++){
        q.push({progresses[i], speeds[i]});    
    }
    while(!q.empty()){
        while(q.front().first + q.front().second * curtime < 100) curtime++;
        while(q.front().first + q.front().second * curtime >= 100){
            ans++;
            q.pop();
        }
        answer.push_back(ans);
        ans = 0;
    }
    return answer;
}