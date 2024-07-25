#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a;
    int idx;
}Person;
Person p[502], toSort[502];
int v[501];
int N, M;

int compare(const void *a, const void *b){
    Person A = *(Person*)a;
    Person B = *(Person*)b;
    if(A.a > B.a) return 1;
    if(A.a == B.a && A.idx > B.idx) return 1;
    return -1; 
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &p[i].a);
        p[i].idx = i;
        if(i < M) toSort[i] = p[i];
    }
    for(int i = 0; i < N - M + 1; i++) scanf("%d", &v[i]);

    int idx = M;
    for(int i = 0; i < N - M + 1; i++){
        qsort(toSort, M, sizeof(Person), compare);
        toSort[v[i] - 1] = p[idx++];
    }
    qsort(toSort, M, sizeof(Person), compare);
    for(int i = 1; i < M; i++) printf("%d ", toSort[i].a);
}
