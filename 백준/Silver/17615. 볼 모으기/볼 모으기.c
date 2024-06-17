#include <stdio.h>

char balls[500001];

int main(void){
    int N;
    scanf("%d", &N);
    scanf("%s", balls);
    char firstC = balls[0];
    char otherC = firstC == 'R' ? 'B' : 'R';
    int fNum = 0, oNum = 0;
    int cnt = 1;
    for(int i = 1; i < N; i++){
        if(balls[i] == balls[i - 1]) cnt++;
        else{
            if(balls[i] == firstC) oNum += cnt;
            else fNum += cnt;
            cnt = 1;
        }
    }
    int fcnt = 0;
    for(int i = 0; i < N; i++){
        if(balls[i] != firstC) break;
        fcnt++;
    }
    if(balls[0] == balls[N - 1]){
        if(fcnt > cnt) fNum = fNum - fcnt + cnt;
    }else fNum -= fcnt;

    printf("%d\n", fNum < oNum ? fNum : oNum);
}