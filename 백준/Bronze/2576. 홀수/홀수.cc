#include <iostream>
using namespace std;
int main(void){
    int num, sum = 0, minval = 101;
    for(int i = 0; i < 7; i++){
        cin >> num;
        if(num & 1){
            minval = min(minval, num);
            sum += num;
        }
    }
    if(!sum) cout << -1;
    else cout << sum << '\n' << minval;
}