#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, P, newScore;

int main(void){
    cin >> N >> newScore >> P;
    vector<int> rank;
    int score;
    for(int i = 0; i < N; i++){
        cin >> score;
        rank.push_back(score);
    }
    sort(rank.begin(), rank.end(), greater<int>());
    if(rank.size() >= P && rank[P - 1] >= newScore) cout << -1;
    else{
        int idx = rank.size();
        while(idx && rank[idx - 1] <= newScore) idx--;
        cout << idx + 1;
    }
}