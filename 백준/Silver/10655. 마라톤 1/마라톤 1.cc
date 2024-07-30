#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define BUFSIZE 1 << 17
char readbuf[BUFSIZE];
char read(){
    static int rp = BUFSIZE, size = BUFSIZE;
    if(rp == size){
        size = fread(readbuf, 1, BUFSIZE, stdin);
        if(!size) return 0;
        rp = 0;
    }
    return readbuf[rp++];
}
int readInt(){
    int ret = 0;
    int flag = 1;
    char c;
    while(c < '0' || c > '9'){
        if(c == '-') flag = -1;
        c = read();
    }
    while(c & 0x10){
        ret = ret * 10 + (c & 0xf);
        c = read();
    }
    return ret * flag;
}

vector<pair<int, int>> cp;

int main(void){
    // ios_base::sync_with_stdio(false);
    int N, ans = 0;
    // cin >> N;
    N = readInt();
    for(int i = 0; i < N; i++){
        int x, y;
        // cin >> x >> y;
        x = readInt(), y = readInt();
        cp.push_back(make_pair(x, y));
        if(i == 0) continue;
        ans += abs(cp[i].first - cp[i - 1].first) + abs(cp[i].second - cp[i - 1].second);
    }
    int cut = 0;
    for(int i = 0; i < N - 2; i++){
        cut = max(cut, 
        (abs(cp[i].first - cp[i + 1].first) + abs(cp[i].second - cp[i + 1].second)) +
        (abs(cp[i + 1].first - cp[i + 2].first) + abs(cp[i + 1].second - cp[i + 2].second))
        - (abs(cp[i].first - cp[i + 2].first) + abs(cp[i].second - cp[i + 2].second)));
    }
    cout << ans - cut;
}