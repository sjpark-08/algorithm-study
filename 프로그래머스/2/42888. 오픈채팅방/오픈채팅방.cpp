#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> list;
    map<string, string> userMap;
    for(int i = 0; i < record.size(); i++){
        if(record[i][0] == 'E'){
            string uid = record[i].substr(record[i].find_first_of(' '), record[i].find_last_of(' ') - record[i].find_first_of(' '));
            string nickname = record[i].substr(record[i].find_last_of(' ') + 1);
            list.push_back({uid, "enter"});
            userMap[uid] = nickname;
            // cout << uid << ' ' << nickname << '\n';
        }else if(record[i][0] == 'L'){
            // string uid, nickname;
            // int k = 6;
            // while(record[i][k] != ' ') uid.push_back(record[i][k++]);
            string uid = record[i].substr(record[i].find_first_of(' '));
            list.push_back({uid, "leave"});
        }else{
            // string uid, nickname;
            // int k = 7;
            // while(record[i][k] != ' ') uid.push_back(record[i][k++]);
            // k++;
            // while(record[i][k] != ' ') nickname.push_back(record[i][k++]);
            string uid = record[i].substr(record[i].find_first_of(' '), record[i].find_last_of(' ') - record[i].find_first_of(' '));
            string nickname = record[i].substr(record[i].find_last_of(' ') + 1);
            userMap[uid] = nickname;
        }
    }
    
    for(int i = 0; i < list.size(); i++){
        if(list[i].second == "enter"){
            answer.push_back(userMap[list[i].first] + "님이 들어왔습니다.");
        }else{
            answer.push_back(userMap[list[i].first] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}