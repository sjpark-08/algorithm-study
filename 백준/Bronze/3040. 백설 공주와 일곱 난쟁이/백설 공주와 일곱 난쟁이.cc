#include <iostream>
#include <vector>
using namespace std;

int arr[9];
vector<int> result;

void dfs(int depth, int idx, int sum){
    if(depth == 7){
        if(sum != 100) return;
        for(auto v : result) cout << v << '\n';
        return;
    }
    for(int i = idx; i < 9; i++){
        if(sum + arr[i] > 100) continue;
        result.push_back(arr[i]);
        dfs(depth + 1, i + 1, sum + arr[i]);
        result.pop_back();
    }
}

int main(void){
    for(int i = 0; i < 9; i++) cin >> arr[i];
    dfs(0, 0, 0);
}