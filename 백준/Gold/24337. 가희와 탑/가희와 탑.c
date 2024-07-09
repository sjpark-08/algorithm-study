#include <stdio.h>
#define BUFSIZE 1 << 17
char writebuf[BUFSIZE];
int wp = 0;
void WriteInt(int n){
    int tmp = n;
    int cnt = 0;
    while(tmp > 0){
        tmp /= 10;
        cnt++;
    }
    if(wp + cnt + 1 >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    int len = cnt;
    writebuf[wp + cnt] = ' ';
    while(n){
        cnt--;
        writebuf[wp + cnt] = n % 10 + 48;
        n /= 10;
    }
    
    wp += len + 1;
}
#define Max(x, y) ((x) > (y) ? (x) : (y))

int main(void){
    int result[100001];
    int a, b, N;
    scanf("%d %d %d", &N, &a, &b);
    if(a + b > N + 1){
        writebuf[wp++] = '-';
        writebuf[wp++] = '1';
        fwrite(writebuf, 1, wp, stdout);
        return 0;
    }
    
    int idx = N;
    int val = 0;
    while(val < b) result[idx--] = ++val;
    if(a < b){
        val = a - 1;
        while(val > 1) result[idx--] = val--;
        while(idx > 0) result[idx--] = 1;
    }else{
        val = a;
        idx++;
        while(val > 1) result[idx--] = val--;
        while(idx > 0) result[idx--] = 1;
    }
    if(a == 1){
        result[N - b + 1] = 1;
        result[1] = b;
    }
    for(int i = 1; i <= N; i++) printf("%d ", result[i]);
}