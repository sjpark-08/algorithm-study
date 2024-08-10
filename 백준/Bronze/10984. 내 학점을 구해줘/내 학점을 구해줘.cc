#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    int T;
    cin >> T;
    while(T--){
        float sum = 0, score;
        int total = 0, tmp, N;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> tmp >> score;
            total += tmp;
            sum += score * tmp;
        }
        printf("%d %.1f\n", total, sum / (float)total);
    }
}