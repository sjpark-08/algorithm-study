#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFSIZE 1 << 16
char readbuf[BUFSIZE];
int rp = BUFSIZE;
char ReadChar(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
int ReadInt(){
    char c;
    int ret = 0;
    bool sign = false;
    while(c < '0' || c > '9'){
        if(c == '-') sign = true;
        c = ReadChar();
    }
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return sign ? -ret : ret;
}

int main(void){
    int N;
    int arr[100001];
    N = ReadInt();
    for(int i = 0; i < N; i++) arr[i] = ReadInt();

    int left = 0, right = N - 1;
    int ans = arr[left] + arr[right];
    while(left < right){
        int value = arr[left] + arr[right];
        if(abs(ans) > abs(value))
            ans = value;
        if(value < 0) left++;
        else if(value > 0) right--;
        else break;
    }
    printf("%d\n", ans);
}