#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, G;
    char game;
    string player;

    cin >> N >> game;
    if(game == 'Y') G = 1;
    else if(game == 'F') G = 2;
    else G = 3;

    unordered_map<string, int> pMap;
    for(int i = 0; i < N; i++){
        cin >> player;
        pMap[player]++;
    }
    cout << pMap.size() / G;
}