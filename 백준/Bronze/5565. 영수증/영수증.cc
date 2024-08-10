#include <iostream>
using namespace std;

int main(void){
    int total, tmp, sum = 0;
    cin >> total;
    for(int i = 0; i < 9; i++){
        cin >> tmp;
        sum += tmp;
    }
    cout << total - sum;
}