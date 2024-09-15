#include <iostream>
#include <unordered_set>
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

    unordered_set<string> pSet;
    for(int i = 0; i < N; i++){
        cin >> player;
        pSet.insert(player);
    }
    cout << pSet.size() / G;
}