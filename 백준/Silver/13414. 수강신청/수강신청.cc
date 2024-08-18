#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int K, L;
    string num;
    unordered_map<string, int> pool;
    vector<pair<int, string>> toSort;

    cin >> K >> L;
    for(int i = 0; i < L; i++){
        cin >> num;
        pool[num] = i;
    }
    for(auto p : pool) toSort.push_back(make_pair(p.second, p.first));
    sort(toSort.begin(), toSort.end());
    K = K < toSort.size() ? K : toSort.size();
    for(int i = 0; i < K; i++) cout << toSort[i].second << '\n';
}