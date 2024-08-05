#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
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