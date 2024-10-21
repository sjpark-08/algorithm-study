#include <iostream>
#include <string>
#include <set>
using namespace std;

int convertTime(string time){
    int h = 0, m = 0;
    for(int i = 0; i < 2; i++) h = h * 10 + (time[i] & 0xf);
    for(int i = 3; i < 5; i++) m = m * 10 + (time[i] & 0xf);
    return h * 60 + m;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string S, E, Q, time, name;
    set<string> in, out;
    cin >> S >> E >> Q;
    int s = convertTime(S);
    int e = convertTime(E);
    int q = convertTime(Q);
    while(!cin.eof()){
        cin >> time >> name;
        int t = convertTime(time);
        if(t <= s) in.insert(name);
        else if(e <= t && t <= q) out.insert(name);
    }
    int ans = 0;
    for(auto i : in){
        if(out.find(i) != out.end()) ans++;
    }
    cout << ans;
}