#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, Me, Mn, R, L, S;
    unordered_map<int, int> pMap;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Me >> Mn;
        pMap[Me] = Mn;
    }
    cin >> R;
    for(int i = 0; i < R; i++){
        vector<int> ans;
        cin >> L;
        for(int j = 0; j < L; j++){
            cin >> S;
            if(pMap.find(S) == pMap.end()) continue;
            ans.push_back(pMap[S]);
        }
        if(ans.size() != L) cout << "YOU DIED\n";
        else{
            for(auto a : ans) cout << a << ' ';
            cout << '\n';
        }
    }
}