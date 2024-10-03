#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<string, int>> cache;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

string toLower(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 65 && str[i] <= 90) str[i] += 32;
    }
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0) return cities.size()*5;
    for(int i = 0; i < cities.size(); i++){
        string city = cities[i];
        int idx = -1;
        for(int i = 0; i < cache.size(); i++){
            if(toLower(cache[i].first) == toLower(city)){
                idx = i;
                break;
            }
        }
        if(idx != -1){
            cache[idx].second = answer;
            answer++;
            sort(cache.begin(), cache.end(), compare);
        }else{
            if(cache.size() == cacheSize){
                cache.pop_back();
            }
            cache.push_back({city, answer}); 
            sort(cache.begin(), cache.end(), compare);
            answer += 5;
        }
    }
    
    return answer;
}