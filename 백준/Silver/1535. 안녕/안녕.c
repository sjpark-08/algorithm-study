#include <stdio.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))

int p[21][2], dp[21][101];
int N;

int main(void){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &p[i][0]);
    for(int i = 1; i <= N; i++) scanf("%d", &p[i][1]);
    for(int i = 1; i <= N; i++){
        for(int k = 1; k <= 99; k++){
            if(p[i][0] <= k) dp[i][k] = Max(dp[i - 1][k], dp[i - 1][k - p[i][0]] + p[i][1]);
            else dp[i][k] = dp[i - 1][k];
        }
    }
    printf("%d\n", dp[N][99]);
}
