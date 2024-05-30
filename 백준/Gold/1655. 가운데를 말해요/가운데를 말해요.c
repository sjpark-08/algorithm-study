#include <stdio.h>
#include <stdbool.h>
#define BUFSIZE 1 << 18
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
    bool sign = false;
    while(c < '0'){
        if(c == '-') sign = true;
        c = ReadChar();
    }
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return sign ? -ret : ret;
}

int maxheap[50001], minheap[50001];
int heapsize1, heapsize2;

void insert_maxheap(int item){
    int i = ++heapsize1;
    while(i != 1 && item > maxheap[i >> 1]){
        maxheap[i] = maxheap[i >> 1];
        i >>= 1;
    }
    maxheap[i] = item;
}
void insert_minheap(int item){
    int i = ++heapsize2;
    while(i != 1 && item < minheap[i >> 1]){
        minheap[i] = minheap[i >> 1];
        i >>= 1;
    }
    minheap[i] = item;
}
int delete_maxheap(){
    int item = maxheap[1];
    int temp = maxheap[heapsize1--];
    int parent = 1, child = 2;

    while(child <= heapsize1){
        if(child < heapsize1 && maxheap[child] < maxheap[child | 1]) child++;
        if(temp >= maxheap[child]) break;
        maxheap[parent] = maxheap[child];
        parent = child;
        child <<= 1;
    }
    maxheap[parent] = temp;
    return item;
}
int delete_minheap(){
    int item = minheap[1];
    int temp = minheap[heapsize2--];
    int parent = 1, child = 2;

    while(child <= heapsize2){
        if(child < heapsize2 && minheap[child] > minheap[child | 1]) child++;
        if(temp <= minheap[child]) break;
        minheap[parent] = minheap[child];
        parent = child;
        child <<= 1;
    }
    minheap[parent] = temp;
    return item;
}

int main(void){
    int N, num;
    N = ReadInt();
    for(int i = 1; i <= N; i++){
        num = ReadInt();
        if(!heapsize1) insert_maxheap(num);
        else if(heapsize1 == heapsize2){
            if(num > minheap[1]){
                int trans = delete_minheap();
                insert_maxheap(trans);
                insert_minheap(num);
            }else insert_maxheap(num);
        }else{
            if(num < maxheap[1]){
                int trans = delete_maxheap();
                insert_minheap(trans);
                insert_maxheap(num);
            }else insert_minheap(num);
        }
        printf("%d\n", maxheap[1]);
    }
}
