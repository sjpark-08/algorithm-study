#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int TC, N;
    cin >> TC;
    while(TC--){
        cin >> N;
        cout << "Pairs for " << N << ": ";
        int bound = N & 1 ? N >> 1 : (N >> 1) - 1;
        for(int i = 1; i <= bound; i++){
            int a = i;
            int b = N - i;
            if(a == b) break;
            cout << a << ' ' << b;
            if(i != bound) cout << ", ";
        }
        cout << '\n';
    }
}