#include <iostream>
using namespace std;

int main(void){
    int N, x, y;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        if(x < y) cout << "NO BRAINS\n";
        else cout << "MMM BRAINS\n";
    }
}