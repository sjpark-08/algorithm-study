#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 26000000

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
}QueueType;

void init_queue(QueueType *q){
    q->front = -1;
    q->rear = -1;
}
int isFull(QueueType *q){
    if(q->rear == MAX_SIZE)
        return 1;
    return 0;    
}
int isEmpty(QueueType *q){
    if(q->front == q->rear)
        return 1;
    return 0;
}
void enqueue(QueueType *q, int item){
    if(!isFull(q)){
        q->data[++(q->rear)] = item;
    }
}
int dequeue(QueueType *q){
    if(!isEmpty(q)){
        return q->data[++(q->front)];
    }
}

int main(void){
    int n, k, i;
    QueueType *q = (QueueType*)malloc(sizeof(QueueType));
    init_queue(q);
    int *arr = (int*)malloc(sizeof(int) * n);
    scanf("%d %d", &n, &k);
    for(i = 1; i <= n; i++)
        enqueue(q, i);
    int cnt = 0;
    while(cnt < n){
        for(i = 0; i < k - 1; i++){
            enqueue(q, dequeue(q));
        }
        arr[cnt++] = dequeue(q);
    }

    printf("<");
    for(i = 0; i < n - 1; i++)  
        printf("%d, ", arr[i]);
    printf("%d>\n", arr[i]);
}

