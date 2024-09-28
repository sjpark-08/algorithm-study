#include <iostream>
using namespace std;

int x, y, ans;
int p[19];

void dfs(int depth, int a, int b){
    if(a > x || b > y) return;
    if(a == x && b == y){
        ans = 1;
        return;
    }
    dfs(depth + 1, a + p[depth], b);
    dfs(depth + 1, a, b + p[depth]);
}

int main(void){
    p[0] = 1;
    for(int i = 1; i <= 18; i++) p[i] = p[i - 1] * 3;

    cin >> x >> y;
    dfs(0, 0, 0);
    cout << ans;
}