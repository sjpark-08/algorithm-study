#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, k, t;
    int p[6];
    vector<pair<int, int>> problems;
    cin >> N;
    for(int i = 1; i < 6; i++){
        cin >> p[i];
    }
    for(int i = 0; i < N; i++){
        cin >> k >> t;
        problems.push_back({k, t});
    }
    sort(problems.begin(), problems.end(), compare);
    // for(auto p : problems) cout << p.first << ' ' << p.second << '\n';
    int ans = 0, pidx = 0, level = 1;
    for(int i = 1; i < 6; i++){
        while(i != problems[pidx].first) pidx++;
        for(int k = 0; k < p[i] - 1; k++) ans += problems[pidx + k + 1].second;
        ans += problems[pidx + p[i] - 1].second;
    }
    ans += 240;
    cout << ans;
}