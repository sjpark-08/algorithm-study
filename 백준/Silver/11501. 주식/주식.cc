#include <cstdio>
using namespace std;
#define BUFSIZE 1 << 20
char readbuf[BUFSIZE];
int rp = BUFSIZE;
char read(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
int readInt(){
    char c;
    int ret = 0;
    while(c < '0' || c > '9') c = read();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = read();
    }
    return ret;
}

int main(void){
    int TC, N;
    long long arr[1000001];
    TC = readInt();
    while(TC--){
        long long ans = 0, maxVal = 0;
        N = readInt();
        for(int i = 0; i < N; i++) arr[i] = readInt();
        for(int i = N - 1; i >= 0; i--){
            if(maxVal < arr[i]) maxVal = arr[i];
            else ans += maxVal - arr[i];
        }
        printf("%lld\n", ans);
    }
}