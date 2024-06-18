#include <stdio.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define BUFSIZE 1 << 14
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
    while(c < '0') c = ReadChar();
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

int map[30000];
int check[3001];
int N, d, k, c;

int main(void){
    N = ReadInt(), d = ReadInt(), k = ReadInt(), c = ReadInt();
    for(int i = 0; i < N; i++) map[i] = ReadInt();

    int cnt = 0;
    for(int i = 0; i < k; i++) if(check[map[i]]++ == 0) cnt++;
    int left = 0, right = k - 1;
    int ans = cnt;
    if(!check[c]) ans++;
    while(left < N){
        if(--check[map[left]] == 0) cnt--;
        left++;
        right = (right + 1) % N;
        if(check[map[right]]++ == 0) cnt++;
        if(check[c]) ans = Max(ans, cnt);
        else ans = Max(ans, cnt + 1);
    }

    printf("%d\n", ans);
}