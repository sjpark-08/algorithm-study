#include <iostream>
using namespace std;

int main(void){
    int K;
    cin >> K;
    int pow[21];
    pow[0] = 1;
    for(int i = 1; i <= 20; i++) pow[i] = pow[i - 1] << 1;

    int minIdx = -1, maxIdx;
    for(int i = 0; i < 20; i++){
        if(!K) break;
        if(K & 1){
            if(minIdx == -1) minIdx = i;
            maxIdx = i;
        }
        K >>= 1;
    }

    int ans, cnt;
    if(minIdx == maxIdx){
        ans = pow[minIdx];
        cnt = 0;
    }else{
        ans = pow[maxIdx + 1];
        cnt = maxIdx - minIdx + 1;
    }
    cout << ans << ' ' << cnt << '\n';
}