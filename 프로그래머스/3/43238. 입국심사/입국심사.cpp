#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calc(long long time, vector<int>& times){
    long long sum = 0;
    for(auto& t : times){
        sum += (time / t);
    }
    return sum;
}

long long solution(int n, vector<int> times) {
    long long answer = 1e14;
    long long left = 0;
    long long right = 1e14;
    
    while(left < right){
        long long mid = left + right >> 1;
        long long possible = calc(mid, times);
        if(possible < n){
            // cout << left << ' ' << right << ' ' << mid << '\n';
            answer = mid;
            left = mid + 1;
        }else right = mid;
    }
    return answer + 1;
}