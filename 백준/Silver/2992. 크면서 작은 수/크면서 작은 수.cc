#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int X, N;
bool visited[7];
int nums[7];
vector<int> values;
set<int> valueSet;

void getNums(int depth, int val){
    if(depth == N){
        valueSet.insert(val);
    }
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        getNums(depth + 1, val * 10 + nums[i]);
        visited[i] = false;
    }
}

int main(void){
    int tmp;
    cin >> X;
    tmp = X;
    while(tmp > 0){
        N++;
        tmp /= 10;
    }
    tmp = X;
    for(int i = N - 1; i >= 0; i--){
        nums[i] = tmp % 10;
        tmp /= 10;
    }
    getNums(0, 0);
    for(auto value : valueSet) values.push_back(value);
    if(values[values.size() - 1] == X) cout << 0;
    else cout << *upper_bound(values.begin(), values.end(), X);
}