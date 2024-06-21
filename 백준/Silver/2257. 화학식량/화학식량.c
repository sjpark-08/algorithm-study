#include <stdio.h>

int stack[201];
int top = -1;
void push(int data){
    stack[++top] = data;
}
int pop(){
    return stack[top--];
}

int main(void){
    char str[101];
    int hydrogen = 1;
    int carbon = 12;
    int oxygen = 16;
    
    scanf("%s", str);
    for(int i = 0; str[i]; i++){
        char c = str[i];
        if(c == '(') push(-1);
        else if(c == ')'){
            int tmp = 0;
            while(stack[top] != -1) tmp += pop();
            pop();
            push(tmp);
        }else if(c >= '2' && c <= '9'){
            int tmp = pop();
            push(tmp * (c & 0xf));
        }else{
            if(c == 'H') push(hydrogen);
            else if(c == 'C') push(carbon);
            else if(c == 'O') push(oxygen);
        }
    }
    
    int ans = 0;
    while(top != -1 && stack[top] != -1) ans += pop();
    printf("%d\n", ans);
}