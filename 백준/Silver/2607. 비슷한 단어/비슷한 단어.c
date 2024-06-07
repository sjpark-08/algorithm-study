#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
int chklist[100];
int tmplist[100];
char tmp[11], origin[11];
int main(void){
    int n, cnt = 0, i, k;
    scanf("%d", &n);
    scanf("%s", origin);
    for(i = 0; origin[i]; i++) chklist[origin[i]]++;
    for(i = 1; i < n; i++){
        scanf("%s", tmp);
        for(k = 0; tmp[k]; k++) tmplist[tmp[k]]++;
        bool fail = false;
        int flag = 0, sum = 0;
        for(k = 'A'; k <= 'Z'; k++){
            tmplist[k] -= chklist[k];
            if(abs(tmplist[k]) > 1){
                fail = true;
                break;
            }
            if(tmplist[k]){
                flag++;
                sum += tmplist[k];
            }
        }
        if(!fail){
            if(flag == 0 || flag == 1) cnt++;
            else if(flag == 2 && abs(sum) < 2) cnt++;
        }
        memset(tmplist, 0, sizeof(int) * 100);
    }
    printf("%d\n", cnt);
}