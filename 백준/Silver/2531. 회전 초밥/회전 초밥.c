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

int map[30001];
int check[3001];
int N, d, k, c;

int main(void){
    N = ReadInt(), d = ReadInt(), k = ReadInt(), c = ReadInt();
    for(int i = 0; i < N; i++) map[i] = ReadInt();

    int ans = 1;
    int right = 0;
    int left = 0;
    // check[map[left]] = 1;
    // while(left < N){
    //     right = (right + 1) % N;
    //     if((right - left + N) % N + 1 > k){
    //         check[map[left]]--;
    //         left++;
    //     }
    //     check[map[right]]++;
    //     for(int i = 1; i <= d; i++) printf("%d ", check[i]); printf("\n");
    //     if(check[map[right]] == 2){
    //         while(left < N && check[map[right]] == 2){
    //             check[map[left]]--;
    //             left++;
    //         }
    //     }
    //     printf("%d %d\n", left, right);
    //     if(check[c]) ans = Max(ans, (right - left + N) % N + 1);
    //     else ans = Max(ans, (right - left + N) % N + 1 + 1);
    // }
    int cnt = 0;
    for(int i = 0; i < k; i++) if(check[map[i]]++ == 0) cnt++;
    left = 0, right = k - 1;
    ans = cnt;
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