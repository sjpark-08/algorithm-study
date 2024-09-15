#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    int N1, N2, T;
    string G1, G2;
    cin >> N1 >> N2;
    cin >> G1 >> G2;
    cin >> T;

    vector<pair<char, int>> list;
    for(int i = N1 - 1; i >= 0; i--) list.push_back({G1[i], 0});
    for(int i = 0; i < N2; i++) list.push_back({G2[i], 1});
    while(T--){
        for(int i = 0; i < N1 + N2 - 1; i++){
            if(list[i].second == 0 && list[i + 1].second == 1){
                swap(list[i], list[i + 1]);
                i++;
            }
        }
    }
    for(int i = 0; i < list.size(); i++) cout << list[i].first;
}