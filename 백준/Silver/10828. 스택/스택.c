#include <stdio.h>
#include <string.h>

int stack[10001];
int top = -1;

void push(int data){
    stack[++top] = data;
}
int pop(){
    return stack[top--];
}

int main(void){
    int N, X;
    char op[6];
    scanf("%d", &N);
    while(N--){
        scanf("%s", op);
        if(op[0] == 'p'){ // push, pop
            if(op[1] == 'u'){
                scanf("%d", &X);
                push(X);
            }else{
                if(top == -1) printf("-1\n");
                else printf("%d\n", pop()); 
            }
        }else if(op[0] == 't'){ // top
            if(top == -1) printf("-1\n");
            else printf("%d\n", stack[top]);
        }else if(op[0] == 's'){ // size
            printf("%d\n", top + 1);
        }else if(op[0] == 'e'){ // empty
            if(top == -1) printf("1\n");
            else printf("0\n");
        }
    }
}