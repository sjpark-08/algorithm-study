#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFSIZE 1 < 17
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
    while(c < '0' || c > '9') c = ReadChar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

typedef struct{
    int vertex;
    int idx;
}Vertex;
typedef struct{
    int capacity;
    int size;
    Vertex *vertice;
}Vector;
typedef struct{
    int nA, nB;
    int idx;
}Edge;
typedef struct{
    int count;
    int rSize;
    Edge edge[100001];
    int last;
}Result;
Vector *vector[100001];
Result result[2];
int parent[100001], visited[100001];
int cnt, last, resNum;

void pushback(int a, int b, int x){
    if(vector[a]->capacity == vector[a]->size){
        vector[a]->capacity <<= 1;
        vector[a]->vertice = realloc(vector[a]->vertice, vector[a]->capacity * sizeof(Vertex));
    }
    vector[a]->vertice[vector[a]->size].vertex = b;
    vector[a]->vertice[vector[a]->size].idx = x;
    vector[a]->size++;
}

void dfs(int now, int resultNum){
    ++cnt;
    visited[now] = resultNum;
    last = now;
    for(int i = 0; i < vector[now]->size; i++){
        int next = vector[now]->vertice[i].vertex;
        if(visited[next]) continue;
        result[resultNum - 1].edge[result[resultNum - 1].rSize].nA = now;
        result[resultNum - 1].edge[result[resultNum - 1].rSize].nB = next;
        result[resultNum - 1].edge[result[resultNum - 1].rSize].idx = vector[now]->vertice[i].idx;
        result[resultNum - 1].rSize++;
        parent[next] = now;
        dfs(next, resultNum);
    }
}

int main(void){
    int N, M, a, b;
    N = ReadInt(), M = ReadInt();
    for(int i = 1; i <= N; i++) parent[i] = i;
    for(int i = 1; i <= N; i++){
        vector[i] = (Vector*)malloc(sizeof(Vector));
        vector[i]->capacity = 2;
        vector[i]->size = 0;
        vector[i]->vertice = (Vertex*)malloc(sizeof(Vector) * vector[i]->capacity);
    }
    for(int i = 1; i <= M; i++){
        a = ReadInt(), b = ReadInt();
        pushback(a, b, i);
        pushback(b, a, i);
    }
    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;
        last = 0, cnt = 0;
        resNum++;
        if(resNum > 2) break;
        dfs(i, resNum);
        result[resNum - 1].count = cnt;
        result[resNum - 1].last = last;
    }
    // for(int i = 1; i <= N; i++) printf("%d ", visited[i]); printf("\n");
    // printf("%d\n", last);
    int p, c;
    if(resNum > 2){
        printf("-1\n");
        return 0;
    }else if(resNum == 2){
        if(result[0].count == result[1].count){
            printf("-1\n");
            return 0;
        }

        printf("%d %d\n", result[0].count, result[1].count);

        for(int i = 1; i <= N; i++){
            if(visited[i] != 1) continue;
            printf("%d ", i);
        }
        printf("\n");
        for(int i = 0; i < result[0].rSize; i++) printf("%d ", result[0].edge[i].idx);
        printf("\n");

        for(int i = 1; i <= N; i++){
            if(visited[i] != 2) continue;
            printf("%d ", i);
        }
        printf("\n");
        for(int i = 0; i < result[1].rSize; i++) printf("%d ", result[1].edge[i].idx);
        printf("\n");
    }else{
        if(result[0].count <= 2) printf("-1\n");
        else{
            c = result[0].last;
            p = parent[c];
            printf("%d %d\n", cnt - 1, 1);
            for(int i = 1; i <= N; i++){
                if(!visited[i] || i == c) continue;
                printf("%d ", i);
            }
            printf("\n");
            for(int i = 0; i < result[0].rSize; i++){
                if((result[0].edge[i].nA == p || result[0].edge[i].nA == c) && (result[0].edge[i].nB == p || result[0].edge[i].nB == c)) continue;
                printf("%d ", result[0].edge[i].idx);
            }
            printf("\n");
            printf("%d\n", c);
            printf("\n");
        }
    }
}