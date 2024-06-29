#include <stdio.h>

int main(void){
    int N, TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &N);
        int ans = 0;
        int even = N >> 1;
        if(N & 1) even++;
        int tmp = (N - 1) / 3;
        while(tmp * 3 + 1 <= N) tmp++;
        if(!(tmp & 1)) tmp++;
        int odd = (N - tmp) / 2 + 1 ; 

        printf("%d\n", even + odd);
    }
}