#include <iostream>
using namespace std;

int main(void){
    int tmp, ansIdx, ans = 0;
    for(int i = 1; i <= 5; i++){
        int sum = 0;
        for(int j = 0; j < 4; j++){
            cin >> tmp;
            sum += tmp;
        }
        if(ans < sum){
            ans = sum;
            ansIdx = i;
        }
    }
    cout << ansIdx << ' ' << ans;
}