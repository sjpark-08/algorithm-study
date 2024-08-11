#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, a, b, sum = 0;
    cin >> N;
    while(N--){
        cin >> a >> b;
        sum += b % a;
    }
    cout << sum;
}