#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    string str;
    vector<int> p, h;
    cin >> N >> K;
    cin >> str;
    for(int i = 0; i < N; i++){
        if(str[i] == 'P') p.push_back(i);
        else h.push_back(i);
    }

    int ans = 0, pIdx = 0, hIdx = 0;
    while(pIdx < p.size() && hIdx < h.size()){
        if(abs(p[pIdx] - h[hIdx]) <= K){
            pIdx++; hIdx++;
            ans++;
        }else{
            if(p[pIdx] < h[hIdx]) pIdx++;
            else hIdx++;
        }
    }
    cout << ans;
}