#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = N; i > 1; i--){
        for(int j = 0; j < N - i; j++) cout << ' ';
        for(int j = 0; j < 2 * i - 1; j++) cout << '*';
        cout << '\n';
    }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < N - i; j++) cout << ' ';
        for(int j = 0; j < 2 * i - 1; j++) cout << '*';
        cout << '\n';
    }
}