#include <iostream>
using namespace std;

int main(void){
    int tmp;
    int a = 2000, b = 2000;
    for(int i = 0; i < 3; i++){
        cin >> tmp;
        a = min(a, tmp);
    }
    for(int i = 0; i < 2; i++){
        cin >> tmp;
        b = min(b, tmp);
    }
    cout << a + b - 50;
}