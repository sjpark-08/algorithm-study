#include <stdio.h>
char c;
int main(){
    scanf("%c", &c);
    if(c == 'N' || c == 'n') printf("Naver D2\n");
    else printf("Naver Whale\n");
}