#include <iostream>
using namespace std;

int main(void){
    int T, v, e;
    cin >> T;
    while(T--){
        cin >> v >> e;
        cout << 2 - v + e << '\n';
    }
}