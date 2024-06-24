#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool visited[101], finished[101];
int match[101], result[101];
int idx;

void dfs(int x){
    visited[x] = true;
    int next = match[x];
    if(!visited[next]) dfs(next);
    else if(!finished[next]){
        for(int i = next; i != x; i = match[i]) result[idx++] = i;
        result[idx++] = x;
    }
    finished[x] = true;
}

int compare(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A > B) return 1;
    return -1;
}

int main(void){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &match[i]);
    for(int i = 1; i <= N; i++) if(!visited[i]) dfs(i);
    qsort(result, idx, sizeof(int), compare);

    printf("%d\n", idx);
    for(int i = 0; i < idx; i++) printf("%d\n", result[i]);
}