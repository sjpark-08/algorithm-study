#include <iostream>
using namespace std;

int main(void){
    int TC, N;
    cin >> TC;
    while(TC--){
        cin >> N;
        int i = 0;
        while(N){
            if(N & 1) cout << i << ' ';
            N >>= 1;
            i++;
        }
        cout << '\n';
    }
}