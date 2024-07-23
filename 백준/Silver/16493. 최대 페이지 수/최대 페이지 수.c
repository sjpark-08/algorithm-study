#include <stdio.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))

int N, M;
int dp[21][201], ch[21][2];

int main(void){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= M; i++) scanf("%d %d", &ch[i][0], &ch[i][1]);
    for(int i = 1; i <= M; i++){
        for(int k = 1; k <= N; k++){
            if(ch[i][0] <= k) dp[i][k] = Max(dp[i - 1][k], dp[i - 1][k - ch[i][0]] + ch[i][1]);
            else dp[i][k] = dp[i - 1][k];
        }
    }
    printf("%d\n", dp[M][N]);
}