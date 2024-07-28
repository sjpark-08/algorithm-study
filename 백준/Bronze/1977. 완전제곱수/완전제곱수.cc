#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int M, N;
    cin >> M >> N;
    int i = sqrt(M);
    int ans = 0, minval = 10000;
    while(true){
        int tmp = i * i;
        if(tmp > N) break;
        if(M <= tmp && tmp <= N){
            ans += tmp;
            minval = min(minval, tmp);
        }
        i++;
    }
    if(ans == 0) cout << "-1" << '\n';
    else cout << ans << '\n' << minval << '\n';
}