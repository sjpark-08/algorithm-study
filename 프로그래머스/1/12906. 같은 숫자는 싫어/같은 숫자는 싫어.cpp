#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(auto data : arr){
        if(answer.size() == 0) {
            answer.push_back(data);
            continue;
        }
        if(answer.back() == data) continue;
        answer.push_back(data);
    }
    
    return answer;
}