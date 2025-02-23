#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if(a.length() == b.length()) {
        return a < b;
    }
    return a.length() > b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    set<string> s;
    
    sort(phone_book.begin(), phone_book.end(), compare);
    
    for(auto phone : phone_book) {
        // cout << phone << '\n';
        if(s.find(phone) != s.end()) return false;
        for(int i = 1; i <= phone.length(); i++) {
            string sub = phone.substr(0, i);
            s.insert(sub);
        }
    }
    
    return answer;
}