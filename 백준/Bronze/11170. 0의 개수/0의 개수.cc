#include <iostream>
using namespace std;

int check(int n){
    if(!n) return 1;
    int cnt = 0;
    while(n > 0){
        if(n % 10 == 0) cnt++;
        n /= 10;
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int TC, N, M;
    cin >> TC;
    while(TC--){
        int ans = 0;
        cin >> N >> M;
        for(int k = N; k <= M; k++) ans += check(k);
        cout << ans << '\n';
    }
}