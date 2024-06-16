#include <stdio.h>
#define MOD 1000000009
/*
int dp[50001][2];

int main(void){
    int N;
    scanf("%d", &N);
    dp[1][0] = 1, dp[1][1] = 0;
    dp[2][0] = 1, dp[2][1] = 0;
    for(int i = 3; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = dp[i - 2][0];
    }
    printf("%d\n", (dp[N][0] + dp[N][1]) % MOD);
}
*/

// advanced
int dp[50001];
int main(void){
    int N;
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3;
    for(int i = 4; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 3]) % MOD;
    }
    printf("%d\n", dp[N]);
}