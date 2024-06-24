#include <stdio.h>
#define SIZE 500001
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data){
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
}
int dequeue(){
    front = (front + 1) % SIZE;
    return queue[front];
}

int main(void){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) queue[i] = i + 1;
    rear = N - 1;
    while(front != rear){
        dequeue();
        if(front == rear) break;
        enqueue(dequeue());
    }
    printf("%d\n", queue[front]);
}