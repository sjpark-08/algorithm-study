#include <iostream>
using namespace std;
int main(void){
    int N, num;
    cin >> N;
    int prev = 0, sum = 0, add = 0;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(num) sum += ++add;
        else add = 0;
    }
    cout << sum;
}