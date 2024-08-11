#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 1; i <= 2 * N - 1; i++){
        int K = i >= N ? N - (i - N) : i;
        int M = 2 * (N - K);
        for(int k = 0; k < K; k++) cout << '*';
        for(int k = 0; k < M; k++) cout << ' ';
        for(int k = 0; k < K; k++) cout << '*';
        cout << '\n';
    }
}