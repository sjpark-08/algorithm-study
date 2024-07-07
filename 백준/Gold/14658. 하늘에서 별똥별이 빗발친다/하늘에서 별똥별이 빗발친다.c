#include <stdio.h>
#include <stdlib.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))

typedef struct{
    int x, y;
}Point;
Point point[101];

int compare(const void *a, const void *b){
    Point A = *(Point*)a;
    Point B = *(Point*)b;
    if(A.x > B.x) return 1;
    else if(A.x == B.x && A.y > B.y) return 1;
    return -1;
}
int compareInt(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A > B) return 1;
    return -1;
}

int main(void){
    int N, M, L, K, x, y;
    scanf("%d %d %d %d", &N, &M, &L, &K);
    for(int i = 0; i < K; i++) scanf("%d %d", &point[i].x, &point[i].y);
    qsort(point, K, sizeof(Point), compare);

    int left = 0;
    int ans = 0;
    for(int right = 0; right < K; right++){
        while(point[right].x - point[left].x > L) left++;
        int leftX = point[left].x;
        int rightX = point[right].x;
        int Y[101];
        int idx = 0;
        for(int i = left; i <= right; i++) Y[idx++] = point[i].y;
        qsort(Y, idx, sizeof(int), compareInt);
        int l = 0, r = 0;
        while(l < idx && r < idx){
            if(Y[r] - Y[l] > L) l++;
            else{
                ans = Max(ans, r - l + 1);
                r++;
            }
        }
    }
    printf("%d\n", K - ans);
}