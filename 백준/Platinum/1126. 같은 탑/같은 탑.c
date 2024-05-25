#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define MAXH 500001

int dp[51][MAXH], h[51];
int N;

int main(void){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &h[i]);
    for(int i = 1; i <= MAXH; i++) dp[0][i] = -1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= MAXH; j++){
            // not use
            dp[i][j] = dp[i - 1][j];
            if(j + h[i] <= MAXH && dp[i - 1][j + h[i]] != -1)
                dp[i][j] = Max(dp[i][j], dp[i - 1][j + h[i]]);
            if(h[i] <= j && dp[i - 1][j - h[i]] != -1) 
                dp[i][j] = Max(dp[i][j], dp[i - 1][j - h[i]] + h[i]);
            if(h[i] >= j && dp[i - 1][h[i] - j] != -1)  
                dp[i][j] = Max(dp[i][j], dp[i - 1][h[i] - j] + j);
        }
    }
    printf("%d\n", dp[N][0] ? dp[N][0] : -1);
}