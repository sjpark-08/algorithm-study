#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxA = 0, maxB = 0;
    for(int i = 0; i < sizes.size(); i++){
        maxA = max(maxA, min(sizes[i][0], sizes[i][1]));
        maxB = max(maxB, max(sizes[i][0], sizes[i][1]));
    }
    answer = maxA * maxB;
    return answer;
}