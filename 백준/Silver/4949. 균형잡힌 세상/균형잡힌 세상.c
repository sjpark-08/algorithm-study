#include <stdio.h>
#include <stdbool.h>
#define BUFSIZE 1 << 15
char readbuf[BUFSIZE], writebuf[BUFSIZE];
int rp = BUFSIZE, wp = 0;
char ReadChar(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
void Write(bool tf){
    if(wp + 5 >= BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
    }
    if(tf){
        writebuf[wp++] = 'y';
        writebuf[wp++] = 'e';
        writebuf[wp++] = 's';
        writebuf[wp++] = '\n';
    }else{
        writebuf[wp++] = 'n';
        writebuf[wp++] = 'o';
        writebuf[wp++] = '\n';
    }
}

char stack[102];
int top = -1;

void push(char data){
    stack[++top] = data;
}
int pop(){
    return stack[top--];
}

int main(void){
    char c;
    while(true){
        c = ReadChar();
        bool fail = false;
        top = -1;
        if(c == '.') break;

        while(c != '.'){
            if(fail){
                c = ReadChar();
                continue;
            }
            if(c == '(' || c == '[') push(c);
            else if(c == ')' || c == ']') {
                if(top == -1) fail = true;
                else{
                    if(stack[top] == '(' && c == ')') pop();
                    else if(stack[top] == '[' && c == ']') pop();
                    else fail = true;
                }
            }
            c = ReadChar();
        }
        if(top != -1 || fail) Write(false);
        else Write(true);

        c = ReadChar(); // LF
    }
    fwrite(writebuf, 1, wp, stdout);
}