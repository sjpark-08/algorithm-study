#include <iostream>
#include <set>
#include <string>
using namespace std;

char num[5][5];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
set<string> myset;

void dfs(int depth, int x, int y, string now){
    if(depth == 5){
        myset.insert(now);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
        now.push_back(num[nx][ny]);
        dfs(depth + 1, nx, ny, now);
        now.pop_back();
    }
}

int main(void){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> num[i][j];
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            string src = "";
            src.push_back(num[i][j]);
            dfs(0, i, j, src);
        }
    }
    cout << myset.size();
}