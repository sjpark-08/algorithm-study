#include <iostream>
#include <vector>
using namespace std;

int T, N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        int cnt[201] = {0, };
        int arr[1001];
        int idx = 1;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            cnt[arr[i]]++;
        }
        vector<int> list[201];
        for(int i = 0; i < N; i++){
            if(cnt[arr[i]] < 6) continue;
            list[arr[i]].push_back(idx++);
        }
        int minSum = 0x7f7f7f7f;
        int ans;
        for(int i = 1; i <= 200; i++){
            if(!list[i].size()) continue;
            int sum = 0;
            for(int k = 0; k < 4; k++) sum += list[i][k];
            if(sum < minSum){
                minSum = sum;
                ans = i;
            }else if(sum == minSum){
                if(list[ans][4] > list[i][4]) ans = i;
            }
        }
        cout << ans << '\n';
    }
}