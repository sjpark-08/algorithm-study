#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    int five = N / 5;
    int ans = -1;
    for(int i = five; i >= 0; i--){
        int tmp = 5 * i;
        int rest = N - tmp;
        if(rest % 3 == 0){
            ans = rest / 3 + i;
            break;
        }
    }
    printf("%d\n", ans);
}