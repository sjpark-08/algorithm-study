#include <iostream>
#include <string>
using namespace std;

int main(void){
    string cur, start;
    cin >> cur >> start;
    int curH = (cur[0] & 0xf) * 10 + (cur[1] & 0xf);
    int curM = (cur[3] & 0xf) * 10 + (cur[4] & 0xf);
    int curS = (cur[6] & 0xf) * 10 + (cur[7] & 0xf);

    int startH = (start[0] & 0xf) * 10 + (start[1] & 0xf);
    int startM = (start[3] & 0xf) * 10 + (start[4] & 0xf);
    int startS = (start[6] & 0xf) * 10 + (start[7] & 0xf);

    int ansS, ansM, ansH;
    if(startS < curS) startM--;
    ansS = (60 + startS - curS) % 60;
    if(startM < curM) startH--;
    ansM = (60 + startM - curM) % 60;
    ansH = (24 + startH - curH) % 24;

    string ans;
    ans.push_back(ansH / 10 + 48);
    ans.push_back(ansH % 10 + 48);
    ans.push_back(':');
    ans.push_back(ansM / 10 + 48);
    ans.push_back(ansM % 10 + 48);
    ans.push_back(':');
    ans.push_back(ansS / 10 + 48);
    ans.push_back(ansS % 10 + 48);

    cout << ans;
}