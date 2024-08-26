#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto command : commands){
        vector<int> toSort;
        for(int i = command[0] - 1; i <= command[1] - 1; i++) 
            toSort.push_back(array[i]);
        sort(toSort.begin(), toSort.end());
        answer.push_back(toSort[command[2] - 1]);
    }
    return answer;
}