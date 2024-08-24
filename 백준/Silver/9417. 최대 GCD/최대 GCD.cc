#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define BUFSIZE 1 << 15
char readbuf[BUFSIZE], c;
int rp = BUFSIZE;
char read(){
    if(rp == BUFSIZE){
        fread(readbuf, 1, BUFSIZE, stdin);
        rp = 0;
    }
    return readbuf[rp++];
}
int readInt(){
    int ret = 0;
    while(c < '0' || c > '9') c = read();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + (c & 0xf);
        c = read();
    }
    return ret;
}

int GCD(int a, int b){
    a = abs(a),  b = abs(b);
    while(b > 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(void){
    int N, M;
    N = readInt();
    for(int t = 0; t < N; t++){
        int ans = 0;
        vector<int> nums;
        // parse
        c = read();
        while(c != '\n'){
            int num = readInt();
            nums.push_back(num);
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                ans = max(ans, GCD(nums[i], nums[j]));
            }
        }
        cout << ans << '\n';
    }
}