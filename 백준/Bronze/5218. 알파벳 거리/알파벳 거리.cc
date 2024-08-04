#include <iostream>
#include <string>
using namespace std;

int main(void){
    int N;
    cin >> N;
    string str1, str2;
    while(N--){
        cin >> str1 >> str2;
        printf("Distances: ");
        for(int i = 0; i < str1.size(); i++){
            int d = str2[i] - str1[i];
            if(d < 0) d += 26;
            printf("%d ", d);
        }
        printf("\n");
    }
}