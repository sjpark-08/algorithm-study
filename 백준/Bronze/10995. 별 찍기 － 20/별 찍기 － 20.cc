#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        if(i & 1){
            for(int k = 0; k < N; k++) cout << " *";
        }else{
            for(int k = 0; k < N; k++){
                if(k == N - 1) cout << "*";
                else cout << "* ";
            }
        }
        cout << '\n';
    }
}