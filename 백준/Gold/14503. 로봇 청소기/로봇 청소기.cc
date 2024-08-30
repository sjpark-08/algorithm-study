#include <iostream>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, ans, x, y, d;
bool map[51][51], done[51][51];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    cin >> x >> y >> d;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    while(true){
        // 1
        if(!done[x][y]){
            done[x][y] = true;
            ans++;
        }

        bool isExist = false;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > N - 1 || ny  > M - 1) continue;
            if(!done[nx][ny] && !map[nx][ny]){
                isExist = true;
                break;
            }
        }
        // 2
        if(!isExist){
            int nx = x - dx[d];
            int ny = y - dy[d];
            if(map[nx][ny]) break;
            x = nx;
            y = ny;
        }else{ // 3
            d = (d - 1 + 4) % 4;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!done[nx][ny] && !map[nx][ny]){
                x = nx;
                y = ny;
            }
        }
    }
    cout << ans;
}