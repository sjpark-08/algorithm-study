#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, arr[50];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0;
    while(true){
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(arr[i] & 1){
                arr[i]--;
                ans++;
            }
            if(arr[i]) cnt++;
        }
        if(!cnt) break;
        for(int i = 0; i < N; i++){
            arr[i] >>= 1;
        }
        ans++;
    }
    cout << ans << '\n';
}