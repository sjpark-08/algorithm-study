#include <stdio.h>
#include <memory.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))

char duck[6] = "quack";
char stack[501][5];
int top[501];
char str[2501];

int main(void){
    int ans = 0;
    scanf("%s", str);
    memset(top, -1, sizeof(top));
    for(int i = 0; str[i]; i++){
        for(int k = 1; k <= 501; k++){
            if(k == 501){
                printf("-1\n");
                return 0;
            }
            if(duck[top[k] + 1] == str[i]){
                ans = Max(ans, k);
                top[k]++;
                if(duck[top[k]] == 'k') top[k] = -1;
                break;
            }
        }
    }
    for(int i = 1; i <= 500; i++){
        if(top[i] != -1){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
}