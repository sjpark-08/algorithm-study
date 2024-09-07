#include <iostream>
using namespace std;

bool match[201][201];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M, a, b;
    cin >> N >> M;
    while(M--){
        cin >> a >> b;
        match[a][b] = match[b][a] = true;
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            if(match[i][j]) continue;
            for(int k = j + 1; k <= N; k++){
                if(match[i][k] || match[j][k]) continue;
                ans++;
            }
        }
    }
    cout << ans;
}