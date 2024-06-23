#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// #define BUFSIZE 1 << 15
// char readbuf[BUFSIZE];
// int rp = BUFSIZE;
// char ReadChar(){
//     if(rp == BUFSIZE){
//         fread(readbuf, 1, BUFSIZE, stdin);
//         rp = 0;
//     }
//     return readbuf[rp++];
// }

char map[3][3];
bool sucX, sucO;
int x, o;

void isPossible(){
    for(int i = 0; i < 3; i++){
        if(map[i][0] == map[i][1] && map[i][1] == map[i][2]){
            if(map[i][0] == 'X') sucX = true;
            else if(map[i][0] == 'O') sucO = true;
        }
    }
    for(int i = 0; i < 3; i++){
        if(map[0][i] == map[1][i] && map[1][i] == map[2][i]){
            if(map[0][i] == 'X') sucX = true;
            else if(map[0][i] == 'O') sucO = true;
        }
    }
    if((map[0][0] == map[1][1] && map[1][1] == map[2][2] || 
        map[0][2] == map[1][1] && map[1][1] == map[2][0])){
            if(map[1][1] == 'X') sucX = true;
            else if(map[1][1] == 'O') sucO = true;
        }
}

int main(void){
    char c;
    char tmp[10];
    while(true){
        x = 0, o = 0;
        sucX = false, sucO = false;
        scanf("%s", tmp);
        if(!strcmp(tmp, "end")) return 0;
        for(int i = 0; i < 9; i++){
            map[i / 3][i % 3] = tmp[i];
            if(tmp[i] == 'X') x++;
            else if(tmp[i] == 'O') o++;
        }
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++){
        //         c = ReadChar();
        //         if(c == 'e') return 0;
        //         map[i][j] = c;
        //         if(c == 'X') x++;
        //         else if(c == 'O') o++;
        //     }
        // }
        if(!(x == o || x == o + 1)){
            printf("invalid\n");
            continue;
        }
        isPossible();
        if(sucX && !sucO && x == o + 1) printf("valid\n");
        else if(!sucX && sucO && x == o) printf("valid\n");
        else if(!sucX && !sucO && x == 5 && o == 4) printf("valid\n");
        else printf("invalid\n"); 

        // while(c != '\n') c = ReadChar();
    }
}