#include <iostream>
#include <set>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    int x, y, z;
    cin >> x >> y >> z;
    if(x + y + z != (x + y + z) / 3 * 3){
        cout << 0;
        return 0;
    }

    set<tuple<int, int, int>> S;
    queue<tuple<int, int, int>> q;
    S.insert({x, y, z});
    q.push({x, y, z});
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();

        if(x == y && y == z){
            cout << 1;
            return 0;
        }
        
        if(x > y){
            int nx = x - y;
            int ny = y + y;
            if(S.find({nx, ny, z}) == S.end()){
                S.insert({nx, ny, z});
                q.push({nx, ny, z});
            }
        }
        if(x < y){
            int nx = x + x;
            int ny = y - x;
            if(S.find({nx, ny, z}) == S.end()){
                S.insert({nx, ny, z});
                q.push({nx, ny, z});
            }
        }
        if(y > z){
            int ny = y - z;
            int nz = z + z;
            if(S.find({x, ny, nz}) == S.end()){
                S.insert({x, ny, nz});
                q.push({x, ny, nz});
            }
        }
        if(y < z){
            int ny = y + y;
            int nz = z - y;
            if(S.find({x, ny, nz}) == S.end()){
                S.insert({x, ny, nz});
                q.push({x, ny, nz});
            }
        }
        if(x > z){
            int nx = x - z;
            int nz = z + z;
            if(S.find({nx, y, nz}) == S.end()){
                S.insert({nx, y, nz});
                q.push({nx, y, nz});
            }
        }
        if(x < z){
            int nx = x + x;
            int nz = z - x;
            if(S.find({nx, y, nz}) == S.end()){
                S.insert({nx, y, nz});
                q.push({nx, y, nz});
            }
        }
    }
    cout << 0;
}