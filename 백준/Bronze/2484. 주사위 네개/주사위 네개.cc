#include <iostream>
#include <algorithm>
using namespace std;

int score[4];

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int calc(){
    pair<int, int> check[7];
    for(int i = 1; i <= 6; i++) check[i].second = i;
    for(int i = 0; i < 4; i++) check[score[i]].first++;
    sort(check, check + 7, compare);
    int ret;
    if(check[0].first == 4) ret = 5000 * check[0].second + 50000;
    else if(check[0].first == 3) ret = 1000 * check[0].second + 10000;
    else if(check[0].first == 2 && check[1].first == 2) ret = 500 * (check[0].second + check[1].second) + 2000;
    else if(check[0].first == 2) ret = 100 * check[0].second + 1000;
    else ret = 100 * check[0].second;

    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> score[0] >> score[1] >> score[2] >> score[3];
        int ret = calc();
        ans = max(ans, ret);
    }
    cout << ans;
}