#include <iostream>
using namespace std;

int main(void){
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ',') ans++;
    }
    cout << ans + 1; 
}