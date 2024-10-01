#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n0, n1, n2, n3, n4, i = 0;
    while(++i){
        string oddOrEven;
        cin >> n0;
        if(!n0) break;
        n1 = 3 * n0;
        if(n1 & 1){
            n2 = n1 + 1 >> 1;
            oddOrEven = "odd";
        }else{
            n2 = n1 >> 1;
            oddOrEven = "even";
        }
        n3 = 3 * n2;
        n4 = n3 / 9;
        cout << i << ". " << oddOrEven << " " << n4 << '\n';
    }
}