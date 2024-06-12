#include <stdio.h>
#define Min(x, y) ((x) < (y) ? (x) : (y))

int main(void){
    int D, P, Q;
    int p, q;
    scanf("%d %d %d", &D, &p, &q);
    P = p > q ? p : q;
    Q = p < q ? p : q;

    int ans = 0x7f7f7f7f;
    // P * Q + Q * x 꼴일 떄부터 값을 구하는 식을 Q로 묶어서 정리해주면 반복되는 것을 알수 있음
    int range = Min(D / P, Q);
    for(int i = 0; i <= range + 1; i++){
        int val = P * i;
        if(val >= D){
            ans = Min(ans, val);
            break;
        }

        int sub = D - val;
        int quo = sub / Q;
        if(sub % Q) ans = Min(ans, val + (quo + 1) * Q);
        else ans = Min(ans, val + quo * Q);
        
        if(ans == D) break;
    }
    printf("%d\n", ans);
}