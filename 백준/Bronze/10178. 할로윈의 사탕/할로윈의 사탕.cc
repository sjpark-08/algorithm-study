#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
    int c, v, TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &c, &v);
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", c / v, c  % v);
    }
}