#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
#define BUFSIZE 1 << 17
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
    int ret = 0;
    char c;
    while(c < '0' || c > '9') c = ReadChar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = ReadChar();
    }
    return ret;
}

bool compare(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second && a.first.size() == b.first.size()) return a.first < b.first;
    else if(a.second == b.second) return a.first.size() > b.first.size();
    return a.second > b.second;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M;
    char c;
    unordered_map<string, int> dict;
    N = ReadInt(), M = ReadInt();
    for(int i = 0; i < N; i++){
        int k = 0;
        string word;
        while((c = ReadChar()) != '\n') word.push_back(c);
        if(word.size() < M) continue;
        dict[word]++;
    } 
    vector<pair<string, int>> ans;
    for(auto word : dict) ans.push_back(word);
    sort(ans.begin(), ans.end(), compare);
    for(auto word : ans) cout << word.first << '\n';
}