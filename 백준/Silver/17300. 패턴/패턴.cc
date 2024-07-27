#include <iostream>
#include <cstdlib>

using namespace std;

bool visited[3][3];

int main(void){
    int L, order[9][2];
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    cin >> L;
    for(int i = 0; i < L; i++){
        int ord;
        cin >> ord;
        ord--;
        order[i][0] = ord / 3;
        order[i][1] = ord % 3;
    }
    visited[order[0][0]][order[0][1]] = true;
    bool suc = true;
    for(int i = 1; i < L; i++){
        if(visited[order[i][0]][order[i][1]]){
            suc = false;
            break;
        }
        if(abs(order[i][0] - order[i - 1][0]) == 2 && abs(order[i][1] - order[i - 1][1]) == 2){
            if(visited[1][1]) visited[order[i][0]][order[i][1]] = true;
        }else if(order[i - 1][1] == order[i][1] && abs(order[i][0] - order[i - 1][0]) == 2){
            if(visited[1][order[i][1]]) visited[order[i][0]][order[i][1]] = true;
        }else if(order[i - 1][0] == order[i][0] && abs(order[i][1] - order[i - 1][1]) == 2){
            if(visited[order[i][0]][1]) visited[order[i][0]][order[i][1]] = true;
        }else{
            visited[order[i][0]][order[i][1]] = true;
        }
        if(!visited[order[i][0]][order[i][1]]){
            suc = false;
            break;
        }
    }
    cout << (suc ? "YES" : "NO");
}