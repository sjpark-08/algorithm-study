#include <iostream>
#include <cstring>
using namespace std;

bool visited[501];

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int TC, P, M, v;
    cin >> TC;
    while(TC--){
        cin >> P >> M;
        memset(visited, false, sizeof(visited));
        int ans = 0;
        for(int i = 0; i < P; i++){
            cin >> v;
            if(visited[v]) ans++;
            else visited[v] = true;
        }
        cout << ans << '\n';
    }
}