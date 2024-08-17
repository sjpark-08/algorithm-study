#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    int arr[600][600];
    for(int i = 0; i < H + X; i++){
        for(int j = 0; j < W + Y; j++){
            cin >> arr[i][j];
        }
    }
    int ans[300][300];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i >= X && j >= Y) continue;
            ans[i][j] = arr[i][j];
        }
    }
    for(int i = X; i < H + X; i++){
        for(int j = Y; j < W + Y; j++){
            if(i < H && j < W) continue;
            ans[i - X][j - Y] = arr[i][j];
        }
    }
    for(int i = X; i < H; i++){
        for(int j = Y; j < W; j++){
            ans[i][j] = arr[i][j] - ans[i - X][j - Y];
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}