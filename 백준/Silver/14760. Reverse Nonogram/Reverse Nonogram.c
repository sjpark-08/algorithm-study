#include <stdio.h>
#include <stdbool.h>
int N;
char map[101][101];

int main(void){
    while(true){
        scanf("%d", &N);
        if(!N) return 0;
        for(int i = 0; i < N; i++) scanf("%s", map[i]);
        for(int i = 0; i < N; i++){
            int cnt = 0;
            bool flag = false;
            for(int j = 0; j < N; j++){
                if(map[i][j] == 'X'){
                    cnt++;
                    flag = true;
                }else{
                    if(j > 0 && map[i][j - 1] == 'X'){
                        printf("%d ", cnt);
                        cnt = 0;
                    }
                }
            }
            if(!flag && !cnt) printf("0");
            if(flag && cnt) printf("%d", cnt);
            printf("\n");
        }
        for(int i = 0; i < N; i++){
            int cnt = 0;
            bool flag = false;
            for(int j = 0; j < N; j++){
                if(map[j][i] == 'X'){
                    cnt++;
                    flag = true;
                }else{
                    if(j > 0 && map[j - 1][i] == 'X'){
                        printf("%d ", cnt);
                        cnt = 0;
                    }
                }
            }
            if(!flag && !cnt) printf("0");
            if(flag && cnt) printf("%d", cnt);
            printf("\n");
        }
    }
}