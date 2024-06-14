#include <stdio.h>
#include <stdbool.h>

int main(void){
    char str[51];
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str);
        int left = 0;
        bool fail = false;
        for(int i = 0; str[i]; i++){
            if(str[i] == '(') left++;
            else{
                if(!left){
                    fail = true;
                    break;
                }else{
                    left--;
                }
            }
        }
        if(left) fail = true;
        printf("%s\n", fail ? "NO" : "YES");
    }
}