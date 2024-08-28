#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, score;
    string name;
    vector<pair<int, string>> cands;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> name >> score;
        cands.push_back({score, name});
    }
    sort(cands.begin(), cands.end(), compare);
    cout << cands[0].second;
}