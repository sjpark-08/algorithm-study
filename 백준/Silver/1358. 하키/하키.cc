#include <iostream>
using namespace std;

int main(void){
    int W, H, X, Y, P, x, y;
    cin >> W >> H >> X >> Y >> P;
    int R = H / 2;
    int ans = 0;
    while(P--){
        cin >> x >> y;
        if(x < X - R || x > X + W + R) continue;
        if(y < Y || y > Y + H) continue;
        if(x >= X && x <= X + W) ans++;
        else if(x < X && (X - x) * (X - x) + (Y + R - y) * (Y + R - y) <= R * R) ans++;
        else if(x > X + W && (X + W - x) * (X + W - x) + (Y + R - y) * (Y + R - y) <= R * R) ans++;
    }
    cout << ans;
}