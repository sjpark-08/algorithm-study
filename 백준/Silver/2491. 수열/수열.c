#include <stdio.h>
#define BUFSIZE 1 < 17
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

#define Max(x, y) ((x) > (y) ? (x) : (y))

int main(void){
    int arr[100001];
    int N;
    N = ReadInt();
    for(int i = 0; i < N; i++) arr[i] = ReadInt();
    
    int leftInc = 0, leftDec = 0, ans = 1;
    for(int right = 1; right < N; right++){
        if(arr[right - 1] > arr[right]) leftInc = right;
        if(arr[right - 1] < arr[right]) leftDec = right;
        ans = Max(ans, Max(right - leftInc + 1, right - leftDec + 1));
    }
    printf("%d\n", ans);
}