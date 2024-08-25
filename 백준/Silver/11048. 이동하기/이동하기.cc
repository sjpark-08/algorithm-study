#include <iostream>
#include <cstdio>
using namespace std;
int map[1001][1001];
int dp[1001][1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] = map[i][j] + max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    cout << dp[N][M];
}