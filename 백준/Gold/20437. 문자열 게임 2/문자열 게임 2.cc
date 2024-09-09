#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    int T, K;
    string W;
    cin >> T;
    while(T--){
        cin >> W >> K;
        int ansMax = 0, ansMin = 10001;
        vector<int> charIndex[26];
        for(int i = 0; i < W.length(); i++){
            charIndex[W[i] - 'a'].push_back(i);
        }
        for(int i = 0; i < 26; i++){
            if(charIndex[i].size() < K) continue;
            for(int k = 0; k < charIndex[i].size() - K + 1; k++){
                ansMax = max(ansMax, charIndex[i][k + K - 1] - charIndex[i][k] + 1);
                ansMin = min(ansMin, charIndex[i][k + K - 1] - charIndex[i][k] + 1);
            }
        }
        if(ansMax > 0) cout << ansMin << ' ' << ansMax << '\n';
        else cout << -1 << '\n';
    }
}