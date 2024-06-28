#include <stdio.h>
#define BUFSIZE 1 << 19
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

char map[100][100];
char str[1000001];

int main(void){
    int N;
    N = ReadInt();
    map['A']['A'] = 'A';
    map['G']['G'] = 'G';
    map['C']['C'] = 'C';
    map['T']['T'] = 'T';
    map['A']['G'] = map['G']['A'] = 'C';
    map['A']['C'] = map['C']['A'] = 'A';
    map['A']['T'] = map['T']['A'] = 'G';
    map['G']['C'] = map['C']['G'] = 'T';
    map['G']['T'] = map['T']['G'] = 'A';
    map['C']['T'] = map['T']['C'] = 'G';

    char c;
    for(int i = 0; i < N; i++) str[i] = ReadChar();
    c = str[N - 1];
    for(int i = N - 2; i >= 0; i--){
        c = map[str[i]][c];
    }
    printf("%c\n", c);
}
