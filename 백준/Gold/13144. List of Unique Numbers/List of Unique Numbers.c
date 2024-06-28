#include <stdio.h>
#include <stdbool.h>
#define BUFSIZE 1 << 17
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
    while(c < '0' || c > '9') c = ReadChar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

int arr[100001];
bool check[100001];

int main(void){
    int N;
    N = ReadInt();
    for(int i = 0; i < N; i++) arr[i] = ReadInt();

    long long ans = 0;
    int left = 0;
    for(int right = 0; right < N; right++){
        while(check[arr[right]]) check[arr[left++]] = false;
        check[arr[right]] = true;
        ans += (right - left + 1);
    }
    printf("%lld\n", ans);
}