#include <iostream>
#include <set>
using namespace std;
int N, arr[20];
set<int> valueSet;

void dfs(int idx, int val){
    if(idx == N){
        valueSet.insert(val);
        return;
    }
    dfs(idx + 1, val + arr[idx]);
    dfs(idx + 1, val);
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    dfs(0, 0);
    int prev = 0, ans = 0;
    for(auto val : valueSet){
        if(val - prev > 1){
            ans = prev + 1;
            break;
        }
        prev = val;
    }
    if(ans) cout << ans;
    else cout << prev + 1;
}