#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int TC, N;
    cin >> TC;
    while(TC--){
        cin >> N;
        while(N--) cout << '=';
        cout << '\n';
    }
}