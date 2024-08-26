#include <cstdio>
using namespace std;
#define BUFSIZE 1 << 20
char readbuf[BUFSIZE], writebuf[BUFSIZE];
int rp = BUFSIZE, wp = 0;
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
void writeInt(int n){
    int tmp = n, cnt = 0;
    while(tmp > 0){
        cnt++;
        tmp /= 10;
    }
    if(wp + cnt + 1 >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    writebuf[wp + cnt] = '\n';
    int len = cnt;
    while(n > 0){
        cnt--;
        writebuf[wp + cnt] = n % 10 + 48;
        n /= 10;
    }
    wp += len + 1;
}

int cnt[10001];

int main(void){
    int N, num;
    N = readInt();
    for(int i = 0; i < N; i++){
        num = readInt();
        cnt[num]++;
    }
    for(int i = 1; i <= 10000; i++){
        if(!cnt[i]) continue;
        for(int k = 0; k < cnt[i]; k++) writeInt(i);
    }
    fwrite(writebuf, 1, wp, stdout);
}