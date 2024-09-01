#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        string nums[10001];
        cin >> n;
        for(int i = 0; i < n; i++) cin >> nums[i];
        sort(nums, nums + n);
        bool flag = false;
        for(int i = 0; i < n - 1; i++){
            if(nums[i].length() > nums[i + 1].length()) continue;
            bool fail = true;
            for(int k = 0; k < nums[i].length(); k++){
                if(nums[i][k] != nums[i + 1][k]){
                    fail = false;
                    break;
                }
            }
            if(fail){
                flag = true;
                break;
            }
        }
        cout << (flag ? "NO" : "YES") << '\n'; 
    }
}