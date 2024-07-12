#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFSIZE 1 << 18
char readbuf[BUFSIZE];
int rp = BUFSIZE;
char ReadChar(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
int ReadInt(){
    char c;
    int ret = 0;
    bool sign = false;
    while(c < '0' || c > '9'){
        if(c == '-') sign = true;
        c = ReadChar();
    }
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return sign ? -ret : ret;
}
#define Max(x, y) ((x) > (y) ? (x) : (y))
int dp[1001][1001][2];
int map[1001][1001];
int N, M;

int main(void){
    N = ReadInt(), M = ReadInt();
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            map[i][j] = ReadInt();

    for(int i = 1; i <= N; i++)
        for(int j = 1;  j <= M; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = -2000000000;

    int sum = 0;
    for(int i = 1; i <= M; i++){
        sum += map[1][i];
        dp[1][i][0] = sum; 
    }

    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j][0] = Max(dp[i - 1][j][0], dp[i - 1][j][1]) + map[i][j];
            dp[i][j][1] = Max(dp[i - 1][j][0], dp[i - 1][j][1]) + map[i][j];
        }
        for(int j = 1; j < M; j++){
            dp[i][j + 1][0] = Max(dp[i][j][0] + map[i][j + 1], dp[i][j + 1][0]);
        }
        for(int j = M; j >= 1; j--){
            dp[i][j - 1][1] = Max(dp[i][j - 1][1], dp[i][j][1] + map[i][j - 1]);
        }
    }

    printf("%d\n", Max(dp[N][M][0], dp[N][M][1]));
}