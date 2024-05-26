#include <stdio.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define BUFSIZE 1 << 18
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

int N, K;
int cnt[100001], arr[200001];

int main(void){
    int num;
    int left = 0, right = 0;
    int ans = 0;
    N = ReadInt(), K = ReadInt();
    for(int i = 0; i < N; i++) arr[i] = ReadInt();
    while(left <= right && right < N){
        if(cnt[arr[right]] < K){
            cnt[arr[right]]++;
            right++;
            ans = Max(ans, right - left);
        }
        else{
            cnt[arr[left]]--;;
            left++;
        }
    }

    printf("%d\n", ans);
}