#include <stdio.h>
#include <stdlib.h>
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
    while(c < '0') c = ReadChar();
    while(c >= '0') {
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

typedef struct{
    int left, right;
}Menu;
Menu menu[100001];
int N, Q;

int BinarySearch(int left, int right, int key){
    int mid;
    while(left < right){
        mid = left + right >> 1;
        if(menu[mid].left < key) left = mid + 1;
        else right = mid;
    }
    return left;
}

int compare(const void *a, const void *b){
    Menu A = *(Menu*)a;
    Menu B = *(Menu*)b;
    if(A.left > B.left) return 1;
    return -1;
}

int main(void){
    int a, b, u, v, x, y;
    N = ReadInt(), Q = ReadInt();
    for(int i = 0; i < N; i++){
        menu[i].left = ReadInt(); // a
        menu[i].right = ReadInt(); // b
    }
    qsort(menu, N, sizeof(Menu), compare);
    
    while(Q--){
        u = ReadInt(), v = ReadInt();
        x = ReadInt(), y = ReadInt();

        int cnt = 0;
        int left = BinarySearch(0, N - 1, u);
        int right = BinarySearch(0, N - 1, v);
        right = menu[right].left > v ? right - 1 : right;

        for(int i = left; i <= right; i++){
            if(v < menu[0].left) break;
            if(x <= menu[i].right && menu[i].right <= y) cnt++;
        }
        printf("%d\n", cnt);
    }
}