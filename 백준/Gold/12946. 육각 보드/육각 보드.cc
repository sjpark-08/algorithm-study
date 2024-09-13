#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

int N, ans;
int dx[6] = {-1, -1, 0, 1, 1, 0};
int dy[6] = {0, 1, 1, 0, -1, -1};
int color[51][51];
string cmap[51];

void dfs(int x, int y, int c){
    color[x][y] = c;
    ans = max(ans, 1);
    for(int i = 0; i < 6; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1) continue;
        if(cmap[nx][ny] != 'X') continue;
        if(color[nx][ny] == -1){
            dfs(nx, ny, 1 -c);
            ans = max(ans, 2);
        }else if(color[nx][ny] == c){
            ans = max(ans, 3);
            cout << ans;
            exit(0);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(color, -1, sizeof(color));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> cmap[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cmap[i][j] == 'X' && color[i][j] == -1) dfs(i, j, 0);
        }
    }
    cout << ans;
}