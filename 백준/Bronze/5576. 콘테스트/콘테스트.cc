#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int w[10], k[10];
    for(int i = 0; i < 10; i++) cin >> w[i];
    for(int i = 0; i < 10; i++) cin >> k[i];
    sort(w, w + 10, greater<int>());
    sort(k, k + 10, greater<int>());
    cout << w[0] + w[1] + w[2] << ' ';
    cout << k[0] + k[1] + k[2] << '\n';
}