#include <iostream>
#include <unordered_set>
using namespace std;

int N;
int addSet[4] = {1, 5, 10, 50};
unordered_set<int> valueSet;
unordered_set<int> valueSet1;
unordered_set<int> valueSet2;

void dfs1(int depth, int val){
    if(depth == N / 2){
        valueSet1.insert(val);
        return;
    }

    for(int i = 0; i < 4; i++){
        int next = val + addSet[i];
        dfs1(depth + 1, next);
    }
}

void dfs2(int depth, int val){
    if(depth == N - N / 2){
        valueSet2.insert(val);
        return;
    }

    for(int i = 0; i < 4; i++){
        int next = val + addSet[i];
        dfs2(depth + 1, next);
    }
}

int main(void){
    cin >> N;
    dfs1(0, 0);
    dfs2(0, 0);
    for(auto val1 : valueSet1){
        for(auto val2: valueSet2){
            valueSet.insert(val1 + val2);
        }
    }
    cout << valueSet.size();
}