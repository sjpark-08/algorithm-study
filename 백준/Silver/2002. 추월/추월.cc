#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<string, int> match;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    string car;

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> car;
        match.insert(make_pair(car, i));
    }
    int ans = 0, minVal = 10000;
    int after[1001];
    for(int i = 1; i <= N; i++){
        cin >> car;
        after[i] = match[car];
    }
    for(int i = N; i >= 1; i--){
        minVal = min(minVal, after[i]);
        if(after[i] > minVal) ans++;
    }
    cout << ans;
}