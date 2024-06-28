#include <stdio.h>
int arr[5];
int main(void){
    int T;
    scanf("%d", &T);
    long long ans = 0;
    for(int i = 0; i < T; i++) scanf("%d", &arr[i]);
    if(arr[0] > arr[2]) ans += (arr[0] - arr[2]) * 508;
    else ans += (arr[2] - arr[0]) * 108;
    if(arr[1] > arr[3]) ans += (arr[1] - arr[3]) * 212;
    else ans += (arr[3] - arr[1]) * 305;
    if(arr[4] > 0) ans += arr[4] * 707;
    ans *= 4763;
    printf("%lld\n", ans);
}