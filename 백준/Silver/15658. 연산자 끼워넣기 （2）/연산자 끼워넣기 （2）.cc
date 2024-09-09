#include <iostream>
using namespace std;

int N, M, cidx;
int arr[11], ops[4], result[50];
int ansMin = 2000000000;
int ansMax = -2000000000;

int calc(){
    int res = 0;
    for(int i = 0; i < N; i++){
        if(result[i] == 0) res += arr[i];
        else if(result[i] == 1) res -= arr[i];
        else if(result[i] == 2) res *= arr[i];
        else res /= arr[i];
    }
    return res;
}

void get(int depth){
    if(depth == N){
        int ret = calc();
        ansMin = min(ansMin, ret);
        ansMax = max(ansMax, ret);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(ops[i] == 0) continue;
        ops[i]--;
        result[depth] = i;
        get(depth + 1);
        ops[i]++;
    }
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    result[0] = 0;
    for(int i = 0; i < 4; i++) cin >> ops[i];
    get(1);
    cout << ansMax << '\n' << ansMin << '\n';
}