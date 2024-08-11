#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int M = N - i - 1, K = 2 * i + 1;
        while(M--) cout << ' ';
        while(K--) cout << '*';
        cout << '\n';
    }
}