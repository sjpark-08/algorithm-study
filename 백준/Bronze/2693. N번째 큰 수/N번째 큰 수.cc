#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int TC, arr[10];
    cin >> TC;
    while(TC--){
        for(int i = 0; i < 10; i++) cin >> arr[i];
        sort(arr, arr + 10, greater<int>());
        cout << arr[2] << '\n';
    }
}