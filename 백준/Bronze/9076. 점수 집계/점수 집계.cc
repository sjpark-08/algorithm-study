#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int TC;
    cin >> TC;
    while(TC--){
        int arr[5];
        for(int i = 0; i < 5; i++) cin >> arr[i];
        sort(arr, arr + 5);
        int ans = 0;
        for(int i = 1; i < 4; i++) ans += arr[i];
        if(arr[3] - arr[1] >= 4) cout << "KIN" << '\n';
        else cout << ans << '\n';
    }

    return 0;
}