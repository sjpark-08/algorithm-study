#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int TC, tmp;
    cin >> TC;
    while(TC--){
        int ans = 0, ansMin = 100;
        for(int i = 0; i < 7; i++){
            cin >> tmp;
            if(tmp & 1) continue;
            ansMin = min(ansMin, tmp);
            ans += tmp;
        }
        cout << ans << ' ' << ansMin << '\n';
    }
}