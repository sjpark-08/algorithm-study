#include <iostream>
#include <string>
using namespace std;
string form;
int ans = 0;
void dfs(int depth, char now){
    if(depth == form.size()){
        ans++;
        return;
    }
    if(form[depth] == 'c'){
        for(int i = 0; i < 26; i++){
            if(now == i + 'a') continue;
            dfs(depth + 1, i + 'a');
        }
    }else{
        for(int i = 0; i <= 9; i++){
            if(now == i + '0') continue;
            dfs(depth + 1, i + '0');
        }
    }
}
using namespace std;
int main(void){
    cin >> form;
    dfs(0, 0);
    cout << ans;
}