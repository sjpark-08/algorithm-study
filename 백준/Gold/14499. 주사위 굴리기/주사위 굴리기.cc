#include <iostream>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int hors[4] = {0, 0, 0, 0};
int vers[4] = {0, 0, 0, 0};
int N, M, x, y, K, direction;
int horB = 0, horT = 2;
int verB = 0, verT = 2;
int map[21][21];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++) 
            cin >> map[i][j];
    for(int i = 0; i < K; i++){
        cin >> direction;
        direction--;
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1) continue;
        
        x = nx, y = ny;
        if(direction < 2){
            horB = (horB + dy[direction] + 4) % 4;
            horT = (horT + dy[direction] + 4) % 4;
            if(map[x][y] == 0) map[x][y] = hors[horB];
            else{
                hors[horB] = map[x][y];
                map[x][y] = 0;
            }
            vers[verB] = hors[horB];
            vers[verT] = hors[horT];
            cout << hors[horT] << '\n';
        }else{
            verB = (verB + dx[direction] + 4) % 4;
            verT = (verT + dx[direction] + 4) % 4;
            if(map[x][y] == 0) map[x][y] = vers[verB];
            else{
                vers[verB] = map[x][y];
                map[x][y] = 0;
            }
            hors[horB] = vers[verB];
            hors[horT] = vers[verT];
            cout << vers[verT] << '\n';
        }
    }
}