#include <stdio.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
int main(void){
    char str[100001];
    int B = 0, S = 0, A = 0, N;
    scanf("%d", &N);
    scanf("%s", str);
    for(int i = 0; i < N; i++){
        if(str[i] == 'B') B++;
        else if(str[i] == 'S') S++;
        else if(str[i] == 'A') A++;
    }
    int max = Max(B, Max(S, A));
    char result[4];
    int idx = 0;
    if(max == B) result[idx++] = 'B';
    if(max == S) result[idx++] = 'S';
    if(max == A) result[idx++] = 'A';
    result[idx] = '\0';

    if(max == B && max == S && max == A) printf("SCU\n");
    else printf("%s\n", result);
}