#include <iostream>
using namespace std;

int main(void){
    int solved[11] = {12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6};
    int penalty[11] = {1600, 894, 1327, 1311, 1004, 1178, 1357, 837, 1055, 556, 773};
    int N;
    cin >> N;
    cout << solved[N - 1] << ' ' << penalty[N - 1];
}