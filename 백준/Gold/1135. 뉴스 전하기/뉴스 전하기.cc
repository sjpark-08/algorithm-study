#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edge[51];
int dp[51];
int N, up;

int dfs(int now){
    vector<int> toSort;
    for(auto next : edge[now]) toSort.push_back(dfs(next));
    sort(toSort.begin(), toSort.end(), greater<int>());
    for(int i = 0; i < toSort.size(); i++){
        dp[now] = max(dp[now], toSort[i] + i);
    }
    return dp[now] + 1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    cin >> up; // -1
    for(int i = 1; i < N; i++){
        cin >> up;
        edge[up].push_back(i);
    }
    dfs(0);
    cout << dp[0];
}