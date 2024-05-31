#include <stdio.h>
#include <memory.h>
int dp[10001][4];

int func(int n, int a){
    if(dp[n][a] >= 0) return dp[n][a];
    if(a == 1) dp[n][a] = func(n - 1, a);
    else if(a == 2) dp[n][a] = func(n - 2, 1) + func(n - 2, 2);
    else dp[n][a] = func(n - 3, 1) + func(n - 3, 2) + func(n - 3, 3);
    return dp[n][a];
}

int main(void){
    int TC, n, i;
    memset(dp, -1, sizeof(int) * 10001 * 4);
    dp[1][1] = 1, dp[1][2] = 0, dp[1][3] = 0;
    dp[2][1] = 1, dp[2][2] = 1, dp[2][3] = 0;
    dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        printf("%d\n", func(n, 1) + func(n , 2) + func(n, 3)); 
    }
}