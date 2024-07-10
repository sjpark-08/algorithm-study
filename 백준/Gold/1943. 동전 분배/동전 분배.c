#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct{
    int cnt;
    int value;
}Coin;
Coin coin[101];
bool d[100001];
int pick[100001];
int N;

int compare(const void *a, const void *b){
    Coin A = *(Coin*)a;
    Coin B = *(Coin*)b;
    if(A.value > B.value) return 1;
    return -1;
}

int main(void){
    for(int t = 0; t < 3; t++){
        int total = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d %d", &coin[i].value, &coin[i].cnt);
            total += coin[i].value * coin[i].cnt;
        }
        qsort(coin, N, sizeof(Coin), compare);
        d[0] = 1;
        for(int i = 0; i < N; i++){
            int idx = 0;
            for(int k = 0; k <= total >> 1; k++){
                if(!d[k]) continue;
                pick[idx++] = k;
            }
            for(int k = 0; k < idx; k++){
                for(int j = 1; j <= coin[i].cnt; j++){
                    int val = pick[k] + coin[i].value * j;
                    if(val > total >> 1) continue;
                    d[val] = true;
                }
            }
        }
        if(total & 1) printf("0\n");
        else printf("%d\n", d[total >> 1] ? 1 : 0);
        memset(d, false, sizeof(d));
    }
    
}