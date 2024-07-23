#include <stdio.h>
#define MOD 10007

int power(int n, int a){
    if(n == 1) return a;

    int tmp = power(n >> 1, a) % MOD;
    if(n & 1) return ((tmp * tmp) % MOD * a) % MOD;
    else return (tmp * tmp) % MOD;
}

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    // N! / (N - K)! * K!
    // (a % M) * (b ^(M - 2) % M) % M
    int dp[1001];
    dp[0] = 1;
    for(int i = 1; i <= 1000; i++){
        dp[i] = (dp[i - 1] * i) % MOD;
    }
    int a = dp[N];
    int b = (dp[N - K] * dp[K]) % MOD;
    printf("%d\n", (a * power(MOD - 2, b)) % MOD);
}