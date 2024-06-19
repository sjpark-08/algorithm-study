#include <stdio.h>
#include <string.h>
#include <memory.h>
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))

int check[26][10002];
char str[10002];

int main(void){
    int T, K;
    scanf("%d", &T);
    while(T--){
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
            int size = check[i][0];
            for(int j = 1; j <= size - K + 1; j++){ 
                ans_min = Min(ans_min, check[i][j + K - 1] - check[i][j] + 1);
                ans_max = Max(ans_max, check[i][j + K - 1] - check[i][j] + 1);
            }
        }

        if(ans_max == 0) printf("-1\n");
        else printf("%d %d\n", ans_min, ans_max);
    }
}