#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int TC, N, X;
    cin >> TC;
    while(TC--){
        cin >> N;
        int minVal = 100, maxVal = 0;
        while(N--){
            cin >> X;
            minVal = min(minVal, X);
            maxVal = max(maxVal, X);
        }
        cout << (maxVal - minVal << 1) << '\n';
    }
}