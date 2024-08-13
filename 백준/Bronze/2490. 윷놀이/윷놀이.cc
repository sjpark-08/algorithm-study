#include <iostream>
using namespace std;
int main(void){
    for(int t = 0; t < 3; t++){
        int sum = 0, num;
        for(int i = 0; i < 4; i++){
            cin >> num;
            sum += num;
        }
        if(sum == 0) cout << "D\n";
        else if(sum == 1) cout << "C\n";
        else if(sum == 2) cout << "B\n";
        else if(sum == 3) cout << "A\n";
        else if(sum == 4) cout << "E\n";

    }
}