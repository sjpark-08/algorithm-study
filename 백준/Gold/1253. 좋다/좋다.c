#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[2001];

int compare(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A > B) return 1;
    return -1;
}

int BinarySearch(int left, int right, int key){
    int mid;
    while(left < right){
        mid = left + right >> 1;
        if(arr[mid] < key) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main(void){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), compare);

    int cnt = 0;
    for(int i = 0; i < N; i++){
        bool suc = false;
        for(int k = 0; k < N; k++){
            if(i == k) continue;
            int idx = BinarySearch(0, N - 1, arr[i] - arr[k]);
            if(arr[i] - arr[k] != arr[idx]) continue;
            int val = arr[idx];
            
            while(idx < N && arr[i] - arr[k] == arr[idx] && arr[idx] == val){
                if(idx != i && idx != k){
                    suc = true;
                    break;
                }
                idx++;
            }
            if(suc) break;
        }
        if(suc) cnt++;
    }
    printf("%d\n", cnt);
}
