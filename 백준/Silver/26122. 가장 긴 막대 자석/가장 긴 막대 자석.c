#include <stdio.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))

int main(void){
    int K;
    char str[300001];

    scanf("%d", &K);
    scanf("%s", str);

    int N = 0 , S = 0;
    int max = 0;
    for(int i = 0; i < K; i++){
        if(str[i] == 'N'){
            if(N > 0 && S > 0 && i > 0 && str[i - 1] == 'S'){
                N = 0;
            }
            N++;
        }else{
            if(N > 0 && S > 0 && i > 0 && str[i - 1] == 'N'){
                S = 0;
            }
            S++;
        }
        max = Max(max, Min(N, S) << 1);
    }
    printf("%d\n", max);
}