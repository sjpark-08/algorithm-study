#include <stdio.h>
#include <stdbool.h>

int main(void){
    char str[51];
    scanf("%s", str);
    int val = 0;
    int interval_sum = 0;
    int sum = 0;
    bool sign = false;
    for(int i = 0; str[i]; i++){
        if(str[i] == '+'){
            if(sign) interval_sum += val;
            else sum += val;
            val = 0;
        }else if(str[i] == '-'){
            if(sign){
                interval_sum += val;
                sum -= interval_sum;
                interval_sum = 0;
            }else sum += val;
            val = 0;
            sign = true;
        }else val = val * 10 + (str[i] & 0xf);
    }
    if(sign) sum -= (interval_sum + val);
    else sum += val;
    printf("%d\n", sum);
}