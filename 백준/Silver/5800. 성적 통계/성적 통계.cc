#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int K, N, arr[51];
    scanf("%d", &K);
    for(int t = 1; t <= K; t++){
        scanf("%d", &N);
        for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
        sort(arr, arr + N);
        int gap = 0;
        for(int i = 0; i < N - 1; i++) gap = max(gap, arr[i + 1] - arr[i]);
        printf("Class %d\nMax %d, Min %d, Largest gap %d\n", t, arr[N - 1], arr[0], gap);
    }
}