#include <stdio.h>

int cnt[16][16];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main(void){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    cnt[1][1] = 1;
    if(K){
        int sx = K % M == 0 ? K / M - 1 : K / M;
        int sy = K % M == 0 ? M : K % M;

        for(int i = 1; i <= sx + 1; i++){
            for(int j = 1; j <= sy; j++){
                for(int k = 0; k < 2; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx > N || ny > M || (nx - 1) * M + ny > K) continue;
                    cnt[nx][ny] += cnt[i][j];
                }
            }
        }

        for(int i = sx + 1; i <= N; i++){
            for(int j = sy; j <= M; j++){
                for(int k = 0; k < 2; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx > N || ny > M) continue;
                    cnt[nx][ny] += cnt[i][j];
                }
            }
        }
    }else{
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                for(int k = 0; k < 2; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx > N || ny > M) continue;
                    cnt[nx][ny] += cnt[i][j];
                }
            }
        }
    }
    printf("%d\n", cnt[N][M]);

}