#include <iostream>
using namespace std;
int main(void){
    int T, N, num;
    cin >> T;
    while(T--){
        cin >> N;
        int sum = 0;
        while(N--){
            cin >> num;
            sum += num;
        }
        cout << sum << '\n';
    }
}