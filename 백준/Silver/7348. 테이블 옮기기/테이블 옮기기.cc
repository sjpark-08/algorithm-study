#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int TC, N, s, t;
    cin >> TC;
    while(TC--){
        cin >> N;
        set<pair<int, int>> moveSet;
        for(int i = 0; i < N; i++){
            cin >> s >> t;
            if(s & 1) s++;
            if(t & 1) t++;
            moveSet.insert({min(s, t), max(s, t)});
        }
        int ans = 0;
        while(moveSet.size()){
            int prev = 0;
            vector<pair<int, int>> toErase;
            for(auto move : moveSet){
                if(prev < move.first){
                    prev = move.second;
                    toErase.push_back(move);
                }
            }
            for(auto a : toErase) moveSet.erase(a);
            ans++;
        }
        cout << ans * 10 << '\n';
    }
}