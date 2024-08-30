#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;
    
    for(auto p : participant) map[p]++;
    for(auto c : completion) map[c]--;
    for(auto m : map){
        if(m.second == 1){
            answer = m.first;
            break;
        }
    }
    return answer;
}