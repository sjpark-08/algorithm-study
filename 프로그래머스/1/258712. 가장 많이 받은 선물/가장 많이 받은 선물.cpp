#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
int given[51][51];
int cntA[51], cntB[51], ans[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> fmap;
    for(int i = 0; i < friends.size(); i++){
        fmap[friends[i]] = i;
    }
    for(int i = 0; i < gifts.size(); i++){
        string a = "", b = "";
        int k = 0;
        while(gifts[i][k] != ' ') a.push_back(gifts[i][k++]);
        for(++k; k < gifts[i].size(); k++) b.push_back(gifts[i][k]);
        int idxA = fmap[a];
        int idxB = fmap[b];
        
        given[idxA][idxB]++;
        cntA[idxA]++;
        cntB[idxB]++;
    }
    
    for(int i = 0; i < friends.size(); i++){
        for(int j = i + 1; j < friends.size(); j++){
            int idxA = i;
            int idxB = j;
            if((!given[idxA][idxB] && !given[idxB][idxA]) ||
                given[idxA][idxB] == given[idxB][idxA]){
                
                    int valueA = cntA[idxA] - cntB[idxA];
                    int valueB = cntA[idxB] - cntB[idxB];
                    if(valueA > valueB){
                        ans[idxA]++;
                    }else if(valueA < valueB){
                        ans[idxB]++;
                    }
            }
            else{
                if(given[idxA][idxB] > given[idxB][idxA]){
                    ans[idxA]++;
                }else if(given[idxA][idxB] < given[idxB][idxA]){
                    ans[idxB]++;
                }
            }
        }
    }
    for(int i = 0; i < friends.size(); i++){
        answer = max(answer, ans[i]);
    }
    return answer;
}