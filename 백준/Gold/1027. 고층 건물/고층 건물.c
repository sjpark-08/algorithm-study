#include <stdio.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))

int main(void){
    int N;
    int arr[51];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);

    int ans = 0;

    for(int i = 0; i < N; i++){
        double max = -1000000001;
        int mid = i;
        int cnt = 0;
        for(int k = mid - 1; k >= 0; k--){
            double curTilt = (arr[k] - arr[mid]) / (double)(mid - k);
            if(curTilt > max){
                max = curTilt;
                cnt++;
            }
        }

        max = -1000000001;
        for(int k = mid + 1; k < N; k++){
            double curTilt = (arr[k] - arr[mid]) / (double)(k - mid);
            if(curTilt > max){
                max = curTilt;
                cnt++;
            }
        }

        ans = Max(ans, cnt);
    }
    printf("%d\n", ans);
}