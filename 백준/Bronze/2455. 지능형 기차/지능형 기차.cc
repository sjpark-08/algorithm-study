#include <iostream>
using namespace std;

int main(void){
    int in, out, sum = 0, ans = 0;
    for(int i = 0; i < 4; i++){
        cin >> out >> in;
        sum += (in - out);
        ans = max(ans, sum);
    }
    cout << ans;
}