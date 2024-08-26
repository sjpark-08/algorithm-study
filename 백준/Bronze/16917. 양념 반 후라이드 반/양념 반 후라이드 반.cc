#include <iostream>
using namespace std;

int main(void){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int total = 0;
    if(A + B > C * 2){
        int tmp = min(X, Y);
        X -= tmp, Y -= tmp;
        total += tmp * C * 2;
    }
    if(X){
        if(A > C * 2) total += C * 2 * X;
        else total += A * X;
    }
    if(Y){
        if(B > C * 2) total += C * 2 * Y;
        else total += B * Y;
    }
    cout << total;
}