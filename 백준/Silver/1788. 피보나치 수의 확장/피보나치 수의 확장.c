#include <stdio.h>
#include <stdlib.h>
int n;
int dp[1000001];

int main(void){
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= 1000000; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
    scanf("%d", &n);
    if(n > 0) printf("1\n%d\n", dp[n]);
    else if(n == 0) printf("0\n0\n");
    else{
        if(n & 1) printf("1\n%d\n", dp[abs(n)]);
        else printf("-1\n%d\n", dp[abs(n)]);
    }
}