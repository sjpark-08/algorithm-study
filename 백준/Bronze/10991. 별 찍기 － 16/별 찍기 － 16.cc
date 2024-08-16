#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = N - i; j > 0; j--) cout << " ";
        for(int k = 0; k < i; k++) {
            if(k == i - 1) cout << "*";
            else cout << "* ";
        }
        cout << '\n';
    }
}