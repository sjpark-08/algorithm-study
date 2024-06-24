#include <stdio.h>
#define BUFSIZE 1 << 15
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
    while(c < '0' || c > '9') c = ReadChar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

int stack[50001];
int top = -1;

void push(int data){
    stack[++top] = data;
}
int pop(){
    return stack[top--];
}

int main(void){
    int N, x, y;
    N = ReadInt();
    int ans = 0;
    for(int i = 0; i < N; i++){
        x = ReadInt(), y = ReadInt();
        if(top == -1){
            push(y);
            continue;
        }
        if(stack[top] < y) push(y);
        else{
            while(stack[top] > y){
                pop();
                ans++;
            }
            if(stack[top] != y) push(y);
        }
    }
    while(top != -1){
        int out = pop();
        if(out) ans++;
    }
    printf("%d\n", ans);
}