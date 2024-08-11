#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int idx = 0;
    for(int i = 1; i <= 2 * N - 1; i++){
        int K = i >= N ? N - idx++ : i;
        int M = N - K;
        while(M--) cout << ' ';
        while(K--) cout << '*';
        cout << '\n';
    }
}