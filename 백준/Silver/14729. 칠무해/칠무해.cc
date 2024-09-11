#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    float arr[10000001];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%f", &arr[i]);
    sort(arr, arr + N);
    for(int i = 0; i < 7; i++) printf("%.3f\n", arr[i]);
}