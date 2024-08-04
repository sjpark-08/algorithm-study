#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
#define BUFSIZE 1 << 15
char readbuf[BUFSIZE], writebuf[BUFSIZE];
int rp = BUFSIZE, wp = 0;
char read(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
void write(char c){
    if(wp == BUFSIZE){
        fwrite(writebuf, 1, wp, stdout);
        wp = 0;
    }
    writebuf[wp++] = c;
}

int main(void){
    int N;
    cin >> N;
    read();
    for(int i = 0; i < N; i++){
        char c = read();
        if(c >= 'a' && c <= 'z') c -= 32;
        write(c);
        while(c != '\n'){
            c = read();
            write(c);
        }
    }
    fwrite(writebuf, 1, wp, stdout);
}