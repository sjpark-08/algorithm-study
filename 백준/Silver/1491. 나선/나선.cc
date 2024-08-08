#include <iostream>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    // 0 ~ N - 1, 0 ~ M - 1
    int left = 0, right = M, up = -1, down = N;
    int x = 0, y = 0;
    while(left < right && up < down){
        // down
        if(x < down - 1) x = --down;
        else break;

        // right
        if(y < right - 1) y = --right;
        else break;

        // up
        if(x > up + 1) x = ++up;
        else break;

        // left
        if(y > left + 1) y = ++left;
        else break;
    }
    if(N == 1) y = M - 1;
    cout << x << ' ' << y;
}