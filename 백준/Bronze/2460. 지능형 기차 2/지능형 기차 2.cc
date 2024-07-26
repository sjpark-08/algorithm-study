#include <iostream>
#include <vector>
using namespace std;

pair<int, int> p[10];

int main(void){
    int a, b;
    for(int i = 0; i < 10; i++) cin >> p[i].first >> p[i].second;
    int ans = 0, total = 0;
    for(int i = 0; i < 10; i++){
        total -= p[i].first;
        total += p[i].second;
        ans = max(ans, total);
    }
    cout << ans;
}