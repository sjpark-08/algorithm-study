#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, score;
    string name;
    cin >> N;
    int ansV = 0;
    string ansN;
    for(int i = 0; i < N; i++){
        cin >> name >> score;
        if(ansV < score){
            ansV = score;
            ansN = name;
        }else if(ansV == score && ansN > name){
            ansN = name;
        }
    }
    cout << ansN;
}