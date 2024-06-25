#include <stdio.h>

int TC, N;
char result[21];

int calculate(){
    int res = 0;
    int i = 0;
    while(result[i] >= '0' && result[i] <= '9'){
        res = res * 10 + (result[i] & 0xf);
        i++;
    }
    while(result[i]){
        char op = result[i++];
        int ret = 0;
        while(result[i] >= '0' && result[i] <= '9'){
            ret = ret * 10 + (result[i] & 0xf);
            i++;
        }
        if(op == '+') res += ret;
        else res -= ret;
    }
    return res;
}

void dfs(int depth, int idx){
    if(depth == N){
        int res = calculate();
        if(res == 0){
            for(int i = 0; i < idx; i++) {
                if(i > 0 && result[i - 1] >= '0' && result[i - 1] <= '9' &&
                            result[i] >= '0' && result[i] <= '9') printf(" %c", result[i]);
                else printf("%c", result[i]);
            }
            printf("\n");
        }
        return;
    }

    result[idx++] = (depth + 1) + '0';
    dfs(depth + 1, idx);
    result[--idx] = 0;

    if(depth != 0){
        result[idx++] = '+';
        result[idx++] = (depth + 1) + '0';
        dfs(depth + 1, idx);
        result[--idx] = 0;
        result[--idx] = 0;

        result[idx++] = '-';
        result[idx++] = (depth + 1) + '0';
        dfs(depth + 1, idx);
        result[--idx] = 0;
        result[--idx] = 0;
    }
    
}

int main(void){

    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &N);
        dfs(0, 0);
        
        printf("\n");
    }
}