#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){

    if(a.second == b.second && a.first.size() == b.first.size()) return a.first < b.first;
    else if(a.second == b.second) return a.first.size() > b.first.size();
    return a.second > b.second;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M;
    string word;
    unordered_map<string, int> dict;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> word;
        if(word.size() < M) continue;
        dict[word]++;
    } 

    vector<pair<string, int>> ans;
    for(auto word : dict) ans.push_back(word);
    sort(ans.begin(), ans.end(), compare);
    for(auto word : ans) cout << word.first << '\n';
}