#include <stdio.h>
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
typedef struct{
    int leftCnt, rightCnt;
    int left, right;
}Building;
typedef struct{
    int height;
    int idx;
}H;
H h[100001];
Building b[100001];
H stack[100002];
int top = -1;

void push(H data){
    stack[++top] = data;
}
H pop(){
    return stack[top--];
}

int main(void){
    int N;
    N = ReadInt();
    for(int i = 1; i <= N; i++){
        h[i].height = ReadInt();
        h[i].idx = i;
    }

    for(int i = 1; i <= N; i++){
        while(top != -1 && stack[top].height <= h[i].height) pop();
        if(top != -1){
            b[i].leftCnt = top + 1;
            b[i].left = stack[top].idx;
        }
        push(h[i]);
    }

    top = -1;

    for(int i = N; i >= 1; i--){
        while(top != -1 && stack[top].height <= h[i].height) pop();
        if(top != -1){
            b[i].rightCnt = top + 1;
            b[i].right = stack[top].idx;
        }
        push(h[i]);
    }

    for(int i = 1; i <= N; i++){
        int cnt = b[i].leftCnt + b[i].rightCnt;
        int left = b[i].left;
        int right = b[i].right;
        if(cnt == 0) printf("0\n");
        else{
            if(right == 0) printf("%d %d\n", cnt, left);
            else if(left == 0) printf("%d %d\n", cnt, right);
            else if(i - left <= right - i) printf("%d %d\n", cnt, left);
            else if(i - left > right - i) printf("%d %d\n", cnt, right);
        }
    }
}