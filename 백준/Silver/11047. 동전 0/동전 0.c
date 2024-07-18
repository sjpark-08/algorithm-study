#include <stdio.h>

int main(void){
    int N, K, ans = 0;
    int coin[10];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d", &coin[i]);
    for(int i = N - 1; i >= 0; i--){
        int quo = K / coin[i];
        if(quo == 0) continue;
        ans += quo;
        K -= coin[i] * quo;
    }
    printf("%d\n", ans);
}