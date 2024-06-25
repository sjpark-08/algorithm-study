#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A < B) return 1;
    return -1;
}

int main(void){
    int TC, N, M;
    int sorted[101], arr[101];
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            sorted[i] = arr[i];
        }
        qsort(sorted, N, sizeof(int), compare);
        int idx = 0;
        int cnt = 0;
        int i = 0;
        while(true){
            if(arr[i] == 0){
                i = (i + 1) % N;
                continue;
            }

            if(sorted[idx] == arr[i]){
                arr[i] = 0;
                idx++;
                cnt++;
                if(i == M) break;
            }
            i = (i + 1) % N;
        }
        printf("%d\n", cnt);
    }   
}