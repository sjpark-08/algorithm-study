#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int get(int n, int k){
    int ret = 0;
    for(int i = 0; i < k; i++){
        ret = ret * 10 + n;
    }
    return ret;
}

int solution(int N, int number) {
    int answer = 0;
    unordered_set<int> numSet[9];
    numSet[1].insert(N);
    for(int k = 2; k <= 8; k++){
        numSet[k].insert(get(N, k));
        for(int i = 1; i < k; i++){
            int j = k - i;
            
            for(auto a : numSet[i]){
                for(auto b : numSet[j]){
                    numSet[k].insert(a + b);
                    numSet[k].insert(a * b);
                    if(a - b > 0) numSet[k].insert(a - b);
                    if(a / b > 0) numSet[k].insert(a / b);
                }
            }
        }
    }
    
    for(int i = 1; i <= 8; i++){
        if(numSet[i].find(number) != numSet[i].end()) return i;   
    }
    return -1;
}