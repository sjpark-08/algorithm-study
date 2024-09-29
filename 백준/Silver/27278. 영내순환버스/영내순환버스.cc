#include <iostream>
using namespace std;

int tsum[100001];
int N, M, t, in, out, maxt, st;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> t;
        tsum[i] = tsum[i - 1] + t;
    }
    for(int i = 0; i < M; i++){
        cin >> in >> out >> st;
        int tmp = st / tsum[N];
        int start, end;
        if(tmp * tsum[N] + tsum[in - 1] >= st) start = tmp * tsum[N] + tsum[in - 1];
        else start = (tmp + 1) * tsum[N] + tsum[in - 1];
        if(in < out) end = start + tsum[out - 1] - tsum[in - 1];
        else end = start + tsum[N] - tsum[in - 1] + tsum[out - 1];
        maxt = max(maxt, end);
    }
    cout << maxt;
}