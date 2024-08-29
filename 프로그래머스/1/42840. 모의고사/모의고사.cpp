#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int vals[3];
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int cnt = 0;
    int maxval = 0;
    for(int i = 0; i < answers.size(); i++){
        if(a[i % 5] == answers[i]) cnt++;
    }
    vals[0] = cnt;
    maxval = max(maxval, cnt);
    
    cnt = 0;
    for(int i = 0; i < answers.size(); i++){
        if(b[i % 8] == answers[i]) cnt++;
    }
    vals[1] = cnt;
    maxval = max(maxval, cnt);
    
    cnt = 0;
    for(int i = 0; i < answers.size(); i++){
        if(c[i % 10] == answers[i]) cnt++;
    }
    vals[2] = cnt;
    maxval = max(maxval, cnt);
    
    for(int i = 0; i < 3; i++){
        if(maxval == vals[i]) answer.push_back(i + 1);
    }
    
    return answer;
}