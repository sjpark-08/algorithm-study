#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    int N;
    cin >> N;
    if(N == 1) cout << "YES\n"<< "1\n";
    else if(N == 2) cout << "NO\n";
    else{
        cout << "YES\n";
        cout << "1 3 2 ";
        string str = "";
        for(int i = 4; i <= N; i++){
            str.append(to_string(i));
            str.push_back(' ');
        }
        cout << str;
    }
}