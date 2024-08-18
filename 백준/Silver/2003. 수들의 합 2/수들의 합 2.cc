#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, M, arr[10001];
    int left = 0, right, sum = 0, ans = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(right = 0; right < N; right++){
        sum += arr[right];
        while(sum > M) sum -= arr[left++];
        if(sum == M) ans++;
    }
    cout << ans;
}