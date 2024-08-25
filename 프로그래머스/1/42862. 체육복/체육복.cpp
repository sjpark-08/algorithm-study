#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    set<int> lSet, rSet;
    for(auto l : lost) lSet.insert(l);
    for(auto r : reserve) rSet.insert(r);
    set<int> lc(lSet);
    set<int> rc(rSet);
    for(auto l : lc){
        if(rc.find(l) != rc.end()){
            lc.erase(l);
            rc.erase(l);
        }
    }
    lSet = lc, rSet = rc;
    lost.clear(), reserve.clear();
    for(auto l : lSet) lost.push_back(l);
    for(auto r : rSet) reserve.push_back(r);
    answer = n - lost.size();
    int rIdx = 0, lIdx = 0;
    
    while(lIdx < lost.size() && rIdx < reserve.size()){
        if(abs(lost[lIdx] - reserve[rIdx]) == 1){
            answer++;
            rIdx++;
            lIdx++;
        }else if(lost[lIdx] < reserve[rIdx]) lIdx++;
        else rIdx++;
    }
    return answer;
}