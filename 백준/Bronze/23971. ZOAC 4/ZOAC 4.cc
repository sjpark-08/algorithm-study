#include <iostream>
using namespace std;
int main(void){
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    int h = H % (N + 1) ? H / (N + 1) + 1 : H / (N + 1);
    int w = W % (M + 1) ? W / (M + 1) + 1 : W / (M + 1);
    cout << h * w;
}