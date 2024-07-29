#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> score;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(void){
    int s;
    for(int i = 1; i <= 8; i++){
        cin >> s;
        score.push_back(make_pair(s, i));
    }
    sort(score.begin(), score.end(), compare);
    int ans = 0;
    for(int i = 0; i < 5; i++) ans += score[i].first;
    cout << ans << '\n';
    vector<int> result;
    for(int i = 0; i < 5; i++) result.push_back(score[i].second);
    sort(result.begin(), result.end());
    for(int i = 0; i < 5; i++) cout << result[i] << ' ';
}