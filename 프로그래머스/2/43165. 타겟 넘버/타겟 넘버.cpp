#include <string>
#include <vector>

using namespace std;

int ans, n, tar;
vector<int> nums;

void dfs(int depth, int val){
    if(depth == n){
        if(val == tar) ans++;
        return;
    }
    
    dfs(depth + 1, val - nums[depth]);
    dfs(depth + 1, val + nums[depth]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    nums = numbers;
    tar = target;
    n = numbers.size();
    dfs(0, 0);
    answer = ans;
    return answer;
}