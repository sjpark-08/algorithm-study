#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<pair<int, int>> cp;

int main(void){
    ios_base::sync_with_stdio(false);
    int N, ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        cp.push_back(make_pair(x, y));
        if(i == 0) continue;
        ans += abs(cp[i].first - cp[i - 1].first) + abs(cp[i].second - cp[i - 1].second);
    }
    int cut = 0;
    for(int i = 0; i < N - 2; i++){
        cut = max(cut, 
        (abs(cp[i].first - cp[i + 1].first) + abs(cp[i].second - cp[i + 1].second)) +
        (abs(cp[i + 1].first - cp[i + 2].first) + abs(cp[i + 1].second - cp[i + 2].second))
        - (abs(cp[i].first - cp[i + 2].first) + abs(cp[i].second - cp[i + 2].second)));
    }
    cout << ans - cut;
}