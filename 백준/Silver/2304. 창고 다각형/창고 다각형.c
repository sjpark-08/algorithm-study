#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y;
}Point;
Point p[1001];
Point stack[1001];
int top = -1;

void push(Point data){
    ++top;
    stack[top].x = data.x;
    stack[top].y = data.y;
}
Point pop(){
    return stack[top--];
}

int compare(const void *a, const void *b){
    return (*(Point*)a).x > (*(Point*)b).x;
}
int com(const void *a, const void *b){
    return *(int*)a > *(int*)b;
}

int main(void){
    int N;
    int sum = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d %d", &p[i].x, &p[i].y);
    qsort(p, N, sizeof(Point), compare);
    for(int i = 0; i < N; i++){
        if(top == -1) push(p[i]);
        else if(stack[0].y > p[i].y) push(p[i]);
        else{
            sum += (p[i].x - stack[0].x) * stack[0].y;
            while(top != -1) pop();
            push(p[i]);
        }
    }
    // stack[0].y < last y
    if(top != -1){
        Point cur = pop();
        while(top != -1){
            if(stack[top].y < cur.y) pop();
            else{
                sum += (cur.x - stack[top].x) * cur.y;
                cur = pop();
            }
        }
        sum += cur.y;
    }
    printf("%d\n", sum);
}