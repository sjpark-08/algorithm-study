#include <stdio.h>
int arr[1001];
int N, Q;
int main(void){
    int q, a, b, c, d;
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++) scanf("%d", &arr[i]);

    while(Q--){
        scanf("%d", &q);
        if(q & 1){
            scanf("%d %d", &a, &b);
            long long sum = 0;
            for(int i = a; i <= b; i++) sum += arr[i];
            printf("%lld\n", sum);
            int tmp = arr[a];
            arr[a] = arr[b];
            arr[b] = tmp;
        }else{
            scanf("%d %d %d %d", &a, &b, &c, &d);
            long long sum1 = 0;
            for(int i = a; i <= b; i++) sum1 += arr[i];
            long long sum2 = 0;
            for(int i = c; i <= d; i++) sum2 += arr[i];
            printf("%lld\n", sum1 - sum2);
        }
    }
}