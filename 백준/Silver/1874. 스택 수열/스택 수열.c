#include <stdio.h>
#include <stdbool.h>

#define BUFSIZE 1 << 17
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

int stack[100001];
char result[400002];
int top = -1;

void push(int data){
    stack[++top] = data;
}
int pop(){
    return stack[top--];
}

int main(void){
    int N, num;
    int k = 1;
    int idx = 0;

    N = ReadInt();
    for(int i = 1; i <= N; i++){
        num = ReadInt();
        while(num >= k){
            push(k++);
            result[idx++] = '+';
            result[idx++] = '\n';
        }
        if(top != -1 && stack[top] == num){
            pop();
            result[idx++] = '-';
            result[idx++] = '\n';
            continue;
        }
    }
    if(top != -1) printf("NO\n");
    else printf("%s", result);
}