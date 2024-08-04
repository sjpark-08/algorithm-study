#include <iostream>
using namespace std;

int main(void){
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