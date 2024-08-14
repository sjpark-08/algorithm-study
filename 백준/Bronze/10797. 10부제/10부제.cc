#include <iostream>
using namespace std;
int main(void){
    int N, ans = 0, tmp;
    cin >> N;
    for(int i = 0; i < 5; i++){
        cin >> tmp;
        if(N == tmp) ans++;
    }
    cout << ans;
}