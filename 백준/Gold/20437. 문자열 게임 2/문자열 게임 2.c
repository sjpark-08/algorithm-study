#include <stdio.h>
#include <string.h>
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))

int main(void){
    int T, K;
    scanf("%d", &T);
    while(T--){
        int check[26][10001];
        char str[10001];
        scanf("%s", str);
        scanf("%d", &K);
        for(int i = 0; i < 26; i++) check[i][0] = 0;
        for(int i = 0; str[i]; i++){
            int idx = str[i] - 'a';
            check[idx][0]++;
            check[idx][check[idx][0]] = i;
        }

        int ans_min = 10001, ans_max = 0;
        for(int i = 0; i < 26; i++){
            if(check[i][0] < K) continue;
            int left = 1;
            int right = K;
            while(right <= check[i][0]){
                ans_max = Max(ans_max, check[i][right] - check[i][left] + 1);
                ans_min = Min(ans_min, check[i][right] - check[i][left] + 1);
                left++;
                right++;
            }
        }

        if(!ans_max) printf("-1\n");
        else printf("%d %d\n", ans_min, ans_max);
    }
}