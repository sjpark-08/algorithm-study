#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define BUFSIZE 1 << 18
using namespace std;
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
    char c;
    int ret = 0;
    while(c < '0') c = read();
    while(c >= '0'){
        ret = ret * 10 + (c & 0xf);
        c = read();
    }
    return ret;
}

vector<pair<int, int>> p;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main(void){
    int TC, N, M, t;
    // TC = readInt();
    cin >> TC;
    while(TC--){
        // N = readInt(), M = readInt();
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            // int s = readInt();
            cin >> t;
            p.push_back(make_pair(t, 2));
        }
        for(int i = 0; i < M; i++){
            // int b = readInt();
            cin >> t;
            p.push_back(make_pair(t, 1));
        }
        sort(p.begin(), p.end(), compare);
        if(p[0].second & 1) cout << "B" << '\n';
        else cout << "S" << '\n';
        // for(int i = 0; i < p.size(); i++) cout << p[i].first << ' ' << p[i].second << '\n';
        p.clear();
    }
}