#include <stdio.h>
#include <memory.h>
#define Min(x, y) ((x) < (y) ? (x) : (y))

int A[1001];
int dp[1001];

int main(void){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    for(int i = 1; i <= N; i++){
        for(int k = 1; k <= A[i]; k++){
            if(dp[i] == -1 || i + k > N) continue;
            if(dp[i + k] == -1) dp[i + k] = dp[i] + 1;
            else dp[i + k] = Min(dp[i + k], dp[i] + 1);
        }
    }
    printf("%d\n", dp[N]);
}