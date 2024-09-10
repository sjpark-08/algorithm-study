#include <string>
#include <vector>
#include <iostream>

using namespace std;
int convert(string time){
    int ret = 0;
    ret += ((time[0] & 0xf) * 10 + (time[1] & 0xf)) * 60;
    ret += ((time[3] & 0xf) * 10 + (time[4] & 0xf));
    return ret;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int video_len_val = convert(video_len);
    int pos_val = convert(pos);
    int op_start_val = convert(op_start);
    int op_end_val = convert(op_end);
    
    for(int i = 0; i < commands.size(); i++){
        if(op_start_val <= pos_val && pos_val <= op_end_val) pos_val = op_end_val;
        if(commands[i] == "next"){
            if(pos_val + 10 > video_len_val) pos_val = video_len_val;
            else pos_val += 10;
        }else{
            if(pos_val - 10 < 0) pos_val = 0;
            else pos_val -= 10;
        }
        if(op_start_val <= pos_val && pos_val <= op_end_val) pos_val = op_end_val;
        cout << pos_val << '\n';
    }

    int tmp = pos_val / 60;
    // cout << op_end_val << '\n';
    answer.push_back(tmp / 10 + '0');
    answer.push_back(tmp % 10 + '0');
    tmp = pos_val % 60;
    cout << tmp << '\n';
    answer.push_back(':');
    answer.push_back(tmp / 10 + '0');
    answer.push_back(tmp % 10 + '0');
    
    return answer;
}