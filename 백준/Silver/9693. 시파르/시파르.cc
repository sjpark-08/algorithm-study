#include <iostream>
using namespace std;

int p[7];

int main(void){
    int TC, N;
    p[0] = 1;
    for(int i = 1; i <= 8; i++) p[i] = p[i - 1] * 5;

    int k = 0;
    while(++k){
        cin >> N;
        if(N == 0) break;
        int ans = 0;
        for(int i = 1; i <= 8; i++){
            ans += (N / p[i]);
        }
        cout << "Case #" << k << ": " << ans << '\n';
    }
}