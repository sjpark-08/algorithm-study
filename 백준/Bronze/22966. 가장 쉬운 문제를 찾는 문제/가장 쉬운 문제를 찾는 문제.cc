#include <iostream>
#include <string>
using namespace std;

int main(void){
    int N, level, ansl = 10;
    string problem, ans;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> problem >> level;
        if(ansl > level){
            ansl = level;
            ans = problem;
        }
    }
    cout << ans;
}