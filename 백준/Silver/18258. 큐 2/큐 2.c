#include <stdio.h>
#include <stdbool.h>
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
    bool sign = false;
    int cnt = 0;
    if(n == 0){
        if(wp + 2 >= BUFSIZE){
            fwrite(writebuf, 1, wp, stdout);
            wp = 0;
        }
        writebuf[wp++] = '0';
        writebuf[wp++] = '\n';
        return;
    }
    if(n < 0){
        sign = true;
        n = -n;
        cnt++;
    }
    int tmp = n;
    while(tmp > 0){
        tmp /= 10;
        cnt++;
    }
    if(wp + cnt >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    int len = cnt;
    writebuf[wp + cnt] = '\n';
    while(cnt > 0){
        cnt--;
        writebuf[wp + cnt] = n % 10 + 48;
        n /= 10;
    }
    if(sign) writebuf[wp] = '-';
    wp += len + 1;
}

int queue[2000001];
int front = -1, rear = -1;
void push(int data){
    queue[++rear] = data;
}
int pop(){
    return queue[++front];
}


int main(void){
    char c;
    int N, num;
    N = ReadInt();
    while(N--){
        c = ReadChar();
        if(c == 'p'){
            c = ReadChar();
            if(c == 'u') {
                // push
                num = ReadInt();
                rp--;
                push(num);
            }else{
                if(front == rear) WriteInt(-1);
                else WriteInt(pop());  
            }
        }else if(c == 's') WriteInt(rear - front);
        else if(c == 'e') WriteInt(front == rear ? 1 : 0);
        else if(c == 'f') WriteInt(front == rear ? -1 : queue[front + 1]);
        else if(c == 'b') WriteInt(front == rear ? -1 : queue[rear]);

        while(c != '\n') c = ReadChar(); // LF
    }
    fwrite(writebuf, 1, wp, stdout);
}