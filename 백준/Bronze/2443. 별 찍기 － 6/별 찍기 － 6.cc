#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = N; i >= 1; i--){
        int M = N - i, K = 2 * i - 1;
        while(M--) cout << ' ';
        while(K--) cout << '*';
        cout << '\n';
    }
}