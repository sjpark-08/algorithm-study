#include <iostream>
#include <string>
using namespace std;

int main(void){
    int N;
    string behv;
    cin >> N >> behv;
    
    bool flag = false, drift = false;
    int w = 0;
    for(int i = 0; i < N; i++){
        if(behv[i] == 'W') w++;
        else if(w == 0) flag = !flag;
        else if(w == 1) drift = true;
    }
    if(w < 2) cout << 0;
    else if(drift) cout << 6;
    else if(flag) cout << 1;
    else cout << 5;
}