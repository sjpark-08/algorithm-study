#include <iostream>
using namespace std;
int cnt[101];

int main(void){
    int sum = 0, num;
    for(int i = 0; i < 10; i++){
        cin >> num;
        cnt[num / 10]++;
        sum += num;
    }
    int maxVal = 0, maxCnt = 0;
    for(int i = 0; i <= 100; i++){
        if(maxCnt < cnt[i]){
            maxCnt = cnt[i];
            maxVal = i * 10;
        }
    }
    cout << sum / 10 << '\n' << maxVal << '\n';
}