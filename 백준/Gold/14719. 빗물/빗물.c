#include <stdio.h>

int stack[501], height[501];
int top = -1;
void push(int data){
    stack[++top] = data;
}
int pop(){
    return stack[top--];
}

int main(void){
    int H, M;
    scanf("%d %d", &H, &M);
    int ans = 0;
    for(int i = 1; i <= M; i++) scanf("%d", &height[i]);
    for(int i = 1; i <= M; i++){
        if(top == -1){
            push(i);
            continue;
        }

        if(height[stack[0]] <= height[i]){
            ans += (i - stack[0]) * height[stack[0]];
            while(top != -1) pop();
            push(i);
        }else push(i);
    }
    
    if(top != -1){
        int cur = pop();
        while(top != -1){
            if(height[stack[top]] <= height[cur]) pop();
            else {
                ans += (cur - stack[top]) * height[cur];
                cur = pop();
            }
        }
        ans += height[cur];
    }
    for(int i = 1; i <= M; i++) ans -= height[i];
    printf("%d\n", ans);
}