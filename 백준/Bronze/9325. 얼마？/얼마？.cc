#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--){
        int s, n, q, p;
        cin >> s;
        cin >> n;
        while(n--){
            cin >> q >> p;
            s += q * p;
        }
        cout << s << '\n';
    }
}