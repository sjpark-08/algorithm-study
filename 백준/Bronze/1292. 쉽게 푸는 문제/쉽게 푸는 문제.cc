#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int A, B;
    cin >> A >> B;
    vector<int> v;
    for(int i = 1; i <= 50; i++){
        for(int k = 0; k < i; k++) v.push_back(i);
        if(v.size() >= B) break;
    }
    int ans = 0;
    for(int i = A - 1; i <= B - 1; i++) ans += v[i];
    cout << ans;
}