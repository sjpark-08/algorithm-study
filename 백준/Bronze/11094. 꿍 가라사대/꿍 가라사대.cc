#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(void){
    char s[102];
    int N;
    string str = "Simon says";
    scanf("%d\n", &N);
    for(int i = 0; i < N; i++){
        fgets(s, 102, stdin);
        bool flag = true;
        for(int k = 0; k < str.size(); k++){
            if(str[k] != s[k]){
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        for(int k = str.size(); s[k]; k++) printf("%c", s[k]);
    }
}