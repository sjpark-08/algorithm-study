#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 3 * n; i++){
        for(int j = 0; j < 3 * n; j++){
            if(i / n == 0 && j / n == 0) printf("*");
            else if(i / n == 2 && j / n == 0) printf("*");
            else if(i / n == 0 && j / n == 2) printf("*");
            else if(i / n == 2 && j / n == 2) printf("*");
            else if(i / n == 1 && j / n == 0) printf(" ");
            else if(i / n == 2 && j / n == 1) printf(" ");
            else printf("x");
        }
        printf("\n");
    }
}