// dp[i][j] = min { dp[i-1][k] + (sum[j] - sum[k]) * (j - k) } = min { dp[i-1][k] + C[j][k] } where C[j][k] = (sum[j] - sum[k]) * (j - k) 
#include <stdio.h>
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define BUFSIZE 1 << 15
typedef long long lnt;
char readbuf[BUFSIZE];
int rp = BUFSIZE;
char ReadChar(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
lnt ReadInt(){
    lnt ret = 0;
    char c;
    while(c < '0') c = ReadChar();
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}
lnt dp[801][8001], c[8001], p[8001];
lnt L, G;

void func(int lev, int start, int end, int left, int right) {
    if(start > end) return;
    int mid = (start + end) >> 1;
    int opt = -1;

    for(int i = left; i < Min(mid, right); i++) {
        lnt val = dp[lev - 1][i] + (mid - i) * (p[mid] - p[i]);
        if(opt == -1 || dp[lev][mid] > val) {
            opt = i; dp[lev][mid] = val;
        }
    }
    func(lev, start, mid - 1, left, opt + 1);
    func(lev, mid + 1, end, opt, right);
}

int main() {
    L = ReadInt(), G = ReadInt();
    if(G >= L) G = L;
    for(int i = 1; i <= L; i++) c[i] = ReadInt();
    for(int i = 1; i <= L; i++) p[i] = p[i - 1] + c[i];
    for(int i = 1; i <= L; i++) dp[1][i] = p[i] * i;
    for(int i = 2; i <= G; i++) func(i, 1, L, 0, L);
    printf("%lld\n", dp[G][L]);
    return 0;
}