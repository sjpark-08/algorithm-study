#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long lnt;

lnt gettime(vector<int>& diffs, vector<int>& times, long long limit, int level){
    lnt total_time = 0;
    for(int i = 0; i < diffs.size(); i++){
        lnt sum = 0;
        if(diffs[i] <= level) sum = times[i];
        else{
            lnt prev_time = i ? times[i - 1] : 0;
            sum = (times[i] + prev_time) * (diffs[i] - level) + times[i];
            // cout << prev_time << ' ' << times[i] << ' ' << diffs[i] - level << ' ' << sum <<'\n';
        }
        total_time += sum;
    }
    return total_time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    lnt left = 0, right = 100001;
    while(left < right){
        // cout << left << ' ' << right << '\n';
        lnt mid = left + right >> 1;
        lnt time = gettime(diffs, times, limit, mid);
        // cout << time << '\n';
        if(time > limit){
            left = mid + 1;
            answer = mid;
        }
        else right = mid;
    }
    
    return answer + 1;
}