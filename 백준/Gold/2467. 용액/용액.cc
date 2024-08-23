#include <iostream>
#include <cstdio>
using namespace std;
#define BUFSIZE 1 << 17
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
    bool sign = false;
    while(c < '0' || c > '9'){
        if(c == '-') sign = true;
        c = read();
    }
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = read();
    }
    return sign ? -ret : ret;
}

int main(void){
    int N, arr[100001];
    N = readInt();
    for(int i = 0; i < N; i++) arr[i] = readInt();
    int left = 0, right = N - 1, ans = 0x7f7f7f7f;
    int tmp = arr[left] + arr[right];
    int ansL = left, ansR = right;
    while(left < right){
        int tmp = arr[left] + arr[right];
        if(ans > abs(tmp)){
            ans = abs(tmp);
            ansL = left;
            ansR = right;
        }
        if(tmp < 0) left++;
        else if(tmp > 0) right--;
        else break;
    }
    cout << arr[ansL] << ' ' << arr[ansR];
}
