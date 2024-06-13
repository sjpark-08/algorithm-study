#include <stdio.h>
#include <stdbool.h>
typedef long long int lnt;
#define BUFSIZE 1 << 20
char readbuf[BUFSIZE], writebuf[BUFSIZE];
int rp = BUFSIZE, wp = 0;
char ReadChar(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
lnt ReadInt(){
    lnt ret = 0;
    bool sign = false;
    char c;
    while(c < '0' || c > '9'){
        c = ReadChar();
        if(c == '-') sign = true;
    }
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 15);
        c = ReadChar();
    }
    return sign ? -ret : ret;
}
void WriteInt(lnt n){
    lnt tmp;
    int cnt = 0;
    bool sign = false;
    if(n < 0){
        sign = true;
        n = -n;
        cnt++;
    }
    tmp = n;
    while(tmp){
        tmp /= 10;
        cnt++;
    }
    if(wp + cnt >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    int len = cnt;
    writebuf[wp + cnt] = '\n';
    while(n){
        cnt--;
        writebuf[wp + cnt] = n % 10 + 48;
        n /= 10;
    }
    if(sign) writebuf[wp + cnt - 1] = '-';
    wp += len + 1;
}


lnt tree[2000001];
int n, m, k;

lnt init(){
    for(int i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1|1];
}
void update(int i, lnt dif){
    for(tree[i += n] += dif; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^1];
}
lnt query(int l, int r){
    lnt res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) res += tree[l++];
        if(r & 1) res += tree[--r];
    }
    return res;
}

int main(void){
    int i, a, b;
    lnt c;
    n = ReadInt(); m = ReadInt(); k = ReadInt();
    for(i = n; i < 2 *n; i++) tree[i] = ReadInt();
    init();
    for(i = 0; i < m + k; i++){
        a = ReadInt(), b = ReadInt(), c = ReadInt();
        if(a & 1){
            // update
            lnt dif = c - tree[b - 1 + n];
            update(b - 1, dif);
            tree[b - 1 + n] = c;
        }
        else{
            // sum
            WriteInt(query(b - 1, c));
        }
    }
    fwrite(writebuf, 1, wp, stdout);
}