#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int k = 0; k < i; k++) cout << ' ';
        for(int k = i ; k < N; k++) cout << '*';
        cout << '\n';
    }
}