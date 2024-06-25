#include <stdio.h>
#include <stdbool.h>
#define SIZE 5001
int tree[SIZE << 2];

int init(int node, int start, int end){
    if(start == end) return tree[node] = 1;
    int mid = start + end >> 1;
    return tree[node] = init(node << 1, start, mid) + init(node << 1|1, mid + 1, end);
}
int update(int node, int start, int end, int index){
    tree[node]--;
    if(start == end) return start; // return node number
    int mid = start + end >> 1;
    if(index <= tree[node << 1]) return update(node << 1, start, mid, index); // to left child
    else return update(node << 1|1, mid + 1, end, index - tree[node << 1]); // to right child
}

int main(void){
    int N, K, res;
    scanf("%d %d", &N, &K);
    init(1, 1, N);
    int idx = K;
    printf("<");
    while(true){
        res = update(1, 1, N, idx);
        if(tree[1]) printf("%d, ", res);
        else {
            printf("%d>\n", res);
            break;
        }
        idx = (idx + K - 1) % tree[1];
        if(!idx) idx = tree[1];
    }
}