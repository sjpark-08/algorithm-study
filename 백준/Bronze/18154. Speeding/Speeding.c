#include <stdio.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
int main(void){
    int prev_t = 0, prev_d = 0;
    int N, t, d;
    int max = 0;
    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &t, &d);
        if(!t && !d) continue;
        max = Max(max, (d - prev_d) / (t - prev_t));
        prev_d = d, prev_t = t;
    }
    printf("%d\n", max);
}