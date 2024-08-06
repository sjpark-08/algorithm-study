#include <iostream>
#include <vector>
using namespace std;

vector<int> budgets;
int N, total, budget;

bool isPossible(int limit){
    int sum = 0;
    for(int i = 0; i < budgets.size(); i++){
        if(budgets[i] <= limit) sum += budgets[i];
        else sum += limit;
    }
    return sum <= total;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int maxBudget = 0;
    for(int i = 0; i < N; i++){
        cin >> budget;
        budgets.push_back(budget);
        maxBudget = max(maxBudget, budget);
    }
    cin >> total;
    int left = 0, right = maxBudget + 1;
    int mid;
    int ans = 0;
    while(left < right){
        mid = left + right >> 1;
        if(isPossible(mid)){
            left = mid + 1;
            ans = mid;
        }
        else right = mid;
    }
    cout << ans;
}