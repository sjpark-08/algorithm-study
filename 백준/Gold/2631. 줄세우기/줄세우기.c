#include <stdio.h>
int N;
int arr[201], lis[201];

int BSTLower(int left, int right, int key){
    int mid;
    while(left < right){
        mid = left + right >> 1;
        if(lis[mid] < key) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int i = 1, j = 0;
    lis[0] = arr[0];
    while(i < N){
        if(lis[j] < arr[i]){
            lis[++j] = arr[i];
            // index = j 
        }else{
            int idx = BSTLower(0, j, arr[i]);
            lis[idx] = arr[i];
        }
        i++;
    }
    // j + 1 = LIS length
    printf("%d\n", N - j - 1);
}