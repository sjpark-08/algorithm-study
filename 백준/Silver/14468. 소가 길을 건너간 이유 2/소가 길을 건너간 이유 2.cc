#include <iostream>
#include <memory.h>
using namespace std;

int main(void){
    string str;
    int arr[26][2];
    for(int i = 0; i < 26; i++) arr[i][0] = -1;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(arr[str[i] - 'A'][0] == -1) arr[str[i] - 'A'][0] = i;
        else arr[str[i] - 'A'][1] = i;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        int left = arr[i][0];
        int right = arr[i][1];
        bool chk[26];
        memset(chk, 0, sizeof(chk));
        int interval = 0;
        for(int k = left + 1; k < right; k++){
            if(chk[str[k] - 'A']) interval--;
            else if(!chk[str[k] - 'A'] && arr[str[k] - 'A'][0] == k){
                chk[str[k] - 'A'] = true;
                interval++;
            }
        }
        ans += interval;
    }
    cout << ans;
}