#include <stdio.h>
#include <stdbool.h>
#define BUFSIZE 1 << 18
char readbuf[BUFSIZE], writebuf[BUFSIZE];
int rp = BUFSIZE, wp = 0;
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
void WriteInt(int n){
    int tmp = n;
    int cnt = 0;
    if(n == 0){
        if(wp + 2 >= BUFSIZE){
            fwrite(writebuf, 1, wp, stdout);
            wp = 0;
        }
        writebuf[wp++] = 48;
        writebuf[wp++] = ' ';
        return;
    }
    while(tmp > 0){
        cnt++;
        tmp /= 10;
    }
    if(wp + cnt >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    writebuf[wp + cnt] = ' ';
    int len = cnt;
    while(n){
        cnt--;
        writebuf[wp + cnt] = (n % 10) + 48;
        n /= 10;
    }
    wp += len + 1;
}

int stack[500002];
int tower[500002];
int top = -1;

void push(int data){
    stack[++top] = data;
}
int pop(){
    return stack[top--];
}

int main(void){
    int N, val;
    tower[0] = 0x7f7f7f7f;
    push(0);
    N = ReadInt();
    for(int i = 1; i <= N; i++) tower[i] = ReadInt();
    for(int i = 1; i <= N; i++){
        while(tower[stack[top]] < tower[i]) pop();
        // WriteInt(stack[top]);
        printf("%d ", stack[top]);
        push(i);
    }
    // fwrite(writebuf, 1, wp, stdout);
}