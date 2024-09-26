#include <string>
#include <vector>
#include <iostream>

using namespace std;
int Y, M, D;

bool compare(string privacy, vector<string>& terms){
    int y = 0, m = 0, d = 0;
    for(int i = 0; i < 4; i++) y = y * 10 + (privacy[i] & 0xf);
    for(int i = 5; i < 7; i++) m = m * 10 + (privacy[i] & 0xf);
    for(int i = 8; i < 10; i++) d = d * 10 + (privacy[i] & 0xf);
    // cout << y << ' ' << m << ' ' << d << '\n';
    char type = privacy[11];
    int term = 0;
    for(int i = 0; i < terms.size(); i++){
        if(terms[i][0] == type){
            for(int k = 2; k < terms[i].size(); k++) term = term * 10 + (terms[i][k] & 0xf);
            break;
        }
    }
    m += term;
    while(m > 12){
        m -= 12;
        y += 1;
    }
    cout << y << ' ' << m << ' ' << d << ' ' << type << '\n';
    if(Y > y) {
        cout << 1 << '\n';
        return true;
    }
    else if(Y == y && M > m) return true;
    else if(Y == y && M == m && D >= d) return true;
    else return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    for(int i = 0; i < 4; i++) Y = Y * 10 + (today[i] & 0xf);
    for(int i = 5; i < 7; i++) M = M * 10 + (today[i] & 0xf);
    for(int i = 8; i < 10; i++) D = D * 10 + (today[i] & 0xf);
    // cout << y << ' ' << m << ' ' << d << '\n';
    
    for(int i = 0; i < privacies.size(); i++){
        if(compare(privacies[i], terms)) answer.push_back(i + 1);
    }
    
    
    return answer;
}