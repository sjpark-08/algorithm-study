#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n){
        int cnt = 0, val = 0;
        while(true){
            val = (val * 10) % n + 1;
            cnt++;
            if(val % n == 0) break;
        }
        cout << cnt << '\n';
    }
}