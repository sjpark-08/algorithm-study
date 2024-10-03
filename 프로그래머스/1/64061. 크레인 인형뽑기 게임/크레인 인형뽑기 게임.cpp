#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> stack;
    int N = board.size();
    int idx[30] = {0,};
    for(int i = 0; i < N; i++){
        int j = 0;
        while(j < N && board[j][i] == 0) j++;
        idx[i] = j;
    }

    for(int i = 0; i < moves.size(); i++){
        int move = moves[i] - 1;
        if(idx[move] == N) continue;
        // cout << move << ' ' << idx[move] << '\n';
        int get = board[idx[move]][move];
        if(stack.size() == 0){
            stack.push_back(get);
            // while(idx[move] < N && board[idx[move]][move] == 0) idx[move]++;
            idx[move]++;
            continue;
        }
        
        if(stack[stack.size() - 1] == get){
            answer += 2;
            stack.pop_back();
            idx[move]++;
        }else{
            stack.push_back(get);
            idx[move]++;
        }
        // idx[move]++;
        // for(auto s : stack) cout << s <<' ';
        // cout << '\n';
        // while(idx[move] < N && board[idx[move]][move] == 0) idx[move]++;
    }
    return answer;
}