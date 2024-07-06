#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))

typedef struct{
    char str[101];
    int idx;
}String;
String arr[20001];
int match[20001];

int compare(const void *a, const void *b){
    String A = *(String*)a;
    String B = *(String*)b;

    if(strcmp(A.str, B.str) > 0) return 1;
    return -1;
}

int compareInt(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A > B) return 1;
    return -1;
}

int check(char *str1, char *str2){
    int cnt = 0;
    for(int k = 0; str1[k] && str2[k]; k++){
        if(str1[k] != str2[k]) break;
        cnt++;
    }
    return cnt++;
}

int main(void){
    int N, A, B;
    int max = -1;
    char backup[20001][101];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%s", arr[i].str);
        arr[i].idx = i;
        strcpy(backup[i], arr[i].str);
    }
    qsort(arr, N, sizeof(String), compare);

    for(int i = 0; i < N - 1; i++){
        int cnt = 0;
        for(int k = 0; arr[i].str[k] && arr[i + 1].str[k]; k++){
            if(arr[i].str[k] != arr[i + 1].str[k]) break;
            cnt++;
        }
        max = Max(max, cnt);
        match[arr[i].idx] = Max(match[arr[i].idx], cnt);
        match[arr[i + 1].idx] = Max(match[arr[i + 1].idx], cnt);
    }
    int first = -1;
    char pre[101];
    for(int i = 0; i < N; i++){
        if(first == -1 && match[i] == max){
            first = i;
            strncpy(pre, backup[i], max);
            printf("%s\n", backup[i]);
        }else if(first != -1 && match[i] == max && !strncmp(backup[i], pre, max)){
            printf("%s\n", backup[i]);
            break;
        }
    }
    // for(int i = 0; i < N; i++) printf("%d ", match[i]); printf("\n");
}