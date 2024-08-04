#include <iostream>
#include <string>
using namespace std;

int main(void){
    string N;
    int M;
    cin >> N >> M;
    int value = 0;
    for(int i = 0; i < N.size(); i++) value = value * 10 + (N[i] & 0xf);
    for(int i = 0; i < N.size() * value; i++){
        if(i == M) break;
        cout << N[i % N.size()];
    }
} 