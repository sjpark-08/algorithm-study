#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    int answer = 0;
    for(auto num : nums){
        s.insert(num);
    }
    answer = min(s.size(), nums.size() >> 1);
    return answer;
}