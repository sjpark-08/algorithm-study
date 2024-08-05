#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int TC;
    string order;
    cin >> TC;
    while(TC--){
        cin >> order;
        int direction = 0;
        int x = 0, y = 0;
        int minX = 0, minY = 0, maxX = 0, maxY = 0;
        for(int i = 0; i < order.size(); i++){
            if(order[i] == 'F') x += dx[direction], y += dy[direction];
            else if(order[i] == 'B') x -= dx[direction], y -= dy[direction];
            else if(order[i] == 'R') direction = (direction + 1) % 4;
            else if(order[i] == 'L') direction = (direction - 1 + 4) % 4;
            minX = min(minX, x), maxX = max(maxX, x);
            minY = min(minY, y), maxY = max(maxY, y);
        }
        int ans = (maxX - minX) * (maxY - minY);
        cout << ans << '\n';
    }
}