#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int check[20001][101][101];

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    for(int i = 0; i < routes.size(); i++){
        int t = 0;
        check[0][points[routes[i][0] - 1][0]][points[routes[i][0] - 1][1]]++;
        for(int j = 0; j < routes[i].size() - 1; j++){
            int srcX = points[routes[i][j] - 1][0];
            int srcY = points[routes[i][j] - 1][1];
            int destX = points[routes[i][j + 1] - 1][0];
            int destY = points[routes[i][j + 1] - 1][1];

            int x = srcX, y = srcY;
            // check[t][x][y]++;
            while(x != destX){
                if(x < destX) x++;
                else if(x > destX) x--;
                t++;
                check[t][x][y]++;
            }
            // check[t][srcX][srcY]++;
            while(y != destY){
                if(y < destY) y++;
                else if(y > destY) y--;
                t++;
                check[t][x][y]++;
            }
        }
    }
    
    for(int i = 0; i < 20001; i++){
        for(int j = 1; j < 101; j++){
            for(int k = 1; k < 101; k++){
                if(check[i][j][k] > 1) answer++;
            }
        }
    }
    
    for(int i = 0; i < 7; i++){
        for(int j = 1; j < 8; j++){
            for(int k = 1; k < 8; k++){
                cout << check[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
    return answer;
}