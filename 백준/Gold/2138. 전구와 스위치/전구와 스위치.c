#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char arr[100001], before[100001], after[100001];

int main(void){
    int N;
    scanf("%d", &N);
    scanf("%s", before);
    scanf("%s", after);
    strcpy(arr, before);
    if(!strcmp(before, after)){
        printf("0\n");
        return 0;
    }
    bool suc = false;
    // start O
    before[0] = before[0] == '0' ? '1' : '0';
    before[1] = before[1] == '0' ? '1' : '0';
    int cnt = 1;
    for(int i = 1; i < N; i++){
        if(before[i - 1] == after[i - 1]) continue;
        cnt++;
        for(int k = -1; k <= 1; k++){
            if(i + k >= N) continue;
            before[i + k] = before[i + k] == '0' ? '1' : '0';
        }
        //printf("%d %d %s\n", i, cnt, before);
    }
    if(strcmp(before, after)) cnt = -1;
    // start X
    strcpy(before, arr);
    int cnt2 = 0;
    for(int i = 1; i < N; i++){
        if(before[i - 1] == after[i - 1]) continue;
        cnt2++;
        for(int k = -1; k <= 1; k++){
            if(i + k >= N) continue;
            before[i + k] = before[i + k] == '0' ? '1' : '0';
        }
    }
    if(strcmp(before, after)) cnt2 = -1;

    if(cnt != -1 && cnt2 != -1) printf("%d\n", cnt < cnt2 ? cnt : cnt2);
    else if(cnt == -1) printf("%d\n", cnt2);
    else if(cnt2 == -1) printf("%d\n", cnt);
    else printf("-1\n");
}