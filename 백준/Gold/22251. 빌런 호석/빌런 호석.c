//    0
// 1     2
//    3
// 4     5
//    6

#include <stdio.h>
#include <stdbool.h>
int map[10] = {
    0b1110111, // 0
    0b0100100, // 1
    0b1011101, // 2
    0b1101101, // 3
    0b0101110, // 4
    0b1101011, // 5
    0b1111011, // 6
    0b0100101, // 7
    0b1111111, // 8
    0b1101111  // 9
};
int N, K, P, X;
int cur[6], result[6], cntMap[10][10];
int ans;
bool visited[1000001];

int getDif(int a, int b){
    int val = map[a] ^ map[b];
    int cnt = 0;
    while(val > 0){
        if(val & 1) cnt++;
        val >>= 1;
    }
    return cnt;
}

void dfs(int depth, int curP){
    if(depth == K){
        // P : 1 ~ P
        if(!curP) return;
        int res = 0;
        for(int i = K - 1; i >= 0; i--){
            res = res * 10 + result[i];
        }
        if(res == X || visited[res] || res > N) return;
        visited[res] = true;
        ans++;
        return;
    }

    for(int i = 0; i < 10; i++){
        if(cntMap[cur[depth]][i] + curP > P) continue;

        result[depth] = i;
        dfs(depth + 1, curP + cntMap[cur[depth]][i]);
        result[depth] = 0;
    }
}

int main(void){
    for(int i = 0; i < 10; i++){
        for(int j = i; j < 10; j++){
            cntMap[i][j] = cntMap[j][i] = getDif(i, j);
        }
    }
    // N : maxval
    // X : cur floor
    scanf("%d %d %d %d", &N, &K, &P, &X);
    for(int i = 0; i < K; i++){
        cur[i] = X % 10;
        X /= 10;
    }
    dfs(0, 0);
    printf("%d\n", ans);
}