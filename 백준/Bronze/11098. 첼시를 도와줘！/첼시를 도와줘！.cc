#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int TC, N, price;
    string name;
    cin >> TC;
    while(TC--){
        cin >> N;
        string ans;
        int max = 0;
        while(N--){
            cin >> price >> name;
            if(price > max){
                max = price;
                ans = name;
            }
        }
        cout << ans << '\n';
    }
}