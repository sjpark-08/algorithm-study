#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int convertTime(string time){
    int h = 0, m = 0;
    for(int i = 0; i <= 1; i++) h = h * 10 + (time[i] & 0xf);
    for(int i = 3; i <= 4; i++) m = m * 10 + (time[i] & 0xf);
    cout << h << ' ' << m << '\n';
    return h * 60 + m;
}

int convertCarNum(string carNum){
    int ret = 0;
    for(int i = 0; i < 4; i++) ret = ret * 10 + (carNum[i] & 0xf);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int baseT = fees[0];
    int baseF = fees[1];
    int unitT = fees[2];
    int unitF = fees[3];
    
    map<string, int> carMap;
    map<string, int> timeMap;
    map<string, int> feeMap;
    vector<pair<string, int>> result;
    for(int i = 0; i < records.size(); i++){
        if(records[i][11] == 'I'){
            // int carNum = convertCarNum(records[i].substr(6, 4));
            int time = convertTime(records[i].substr(0, 5));
            cout << records[i].substr(0, 5) << ' ' << time << '\n';
            carMap[records[i].substr(6, 4)] = time;
        }else{
            int out = convertTime(records[i].substr(0, 5));
            int in = carMap[records[i].substr(6, 4)];
            int diff = out - in;
            timeMap[records[i].substr(6, 4)] += diff;
            // feeMap[records[i].substr(6, 4)] += total;
            carMap[records[i].substr(6, 4)] = -1;
            // result.push_back({records[i].substr(6, 4), total});
        }
    }
    // sort(result.begin(), result.end());
    for(auto c : carMap){
        if(c.second != -1){
            int out = convertTime("23:59");
            int in = c.second;
            int diff = out - in;
            timeMap[c.first] += diff;
        }
    }
    for(auto t : timeMap){
        int total = baseF;
        int diff = t.second;
        if(diff > baseT){
            diff -= baseT;
            int mul = diff / unitT;
            if(diff % unitT) mul++;
            total += mul * unitF;
        }
        feeMap[t.first] = total;
    }
    
    for(auto f : feeMap) answer.push_back(f.second);
    
    return answer;
}