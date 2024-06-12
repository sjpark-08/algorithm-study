#include <stdio.h>

int heap[101];
int heapsize;

void insert_maxheap(int item){
    int i = ++heapsize;
    while(i != 1 && item > heap[i >> 1]){
        heap[i] = heap[i >> 1];
        i >>= 1;
    }
    heap[i] = item;
}
int delete_maxheap(){
    int item = heap[1];
    int temp = heap[heapsize--];
    int parent = 1, child = 2;

    while(child <= heapsize){
        if(child < heapsize && heap[child] < heap[child|1]) child++;
        if(temp >= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child <<= 1;
    }
    heap[parent] = temp;
    return item;
}

int main(void){
    int N, num, cur;
    scanf("%d", &N);
    scanf("%d", &num);
    cur = num;
    for(int i = 1; i < N; i++){
        scanf("%d", &num);
        insert_maxheap(num);
    }
    int cnt = 0;
    while(heap[1] >= cur){
        int tmp = delete_maxheap();
        insert_maxheap(--tmp);
        cur++;
        cnt++;
    }
    printf("%d\n", cnt);
}