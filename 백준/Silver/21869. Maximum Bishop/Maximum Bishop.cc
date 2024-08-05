#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    if(N == 1) {
        cout << "1" << '\n' << "1 1" << '\n';
        return 0;
    }
    cout << 2 * (N - 1) <<  '\n';
    for(int i = 1; i <= N; i++) cout << 1 << ' ' << i << '\n';
    for(int i = 2; i <= N - 1; i++) cout << N << ' ' << i << '\n';
}