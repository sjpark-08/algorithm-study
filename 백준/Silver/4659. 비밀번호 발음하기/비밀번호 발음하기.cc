#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    set<char> vowel;
    vowel.insert('a'); vowel.insert('e'); vowel.insert('i');
    vowel.insert('o'); vowel.insert('u');
    string input;
    while(true){
        cin >> input;
        if(input == "end") break;
        int cnt[26] = {0, };
        int vowels = 0, consonant = 0;
        char prev = 0;
        bool fail = false;
        bool vowelCheck = false;
        for(int i = 0; i < input.length(); i++){
            cnt[input[i] - 'a']++;
            if(vowel.find(input[i]) != vowel.end()) vowelCheck = true;
            if(i < input.length() - 1){
                if(input[i] == input[i + 1] && input[i] != 'e' && input[i] != 'o'){
                    fail = true;
                    break;
                }
            }
            if(vowel.find(input[i]) != vowel.end()) vowels++;
            else consonant++;
            if(i > 2){
                if(vowel.find(input[i - 3]) != vowel.end()) vowels--;
                else consonant--;
            }
            if(vowels == 3 || consonant == 3){
                fail = true;
                break;
            }
        }
        if(!vowelCheck) fail = true;
        if(!fail) cout << "<" << input << ">" << " is acceptable.\n";
        else cout << "<" << input << ">" << " is not acceptable.\n";
    }
}