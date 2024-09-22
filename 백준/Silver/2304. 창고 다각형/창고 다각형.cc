#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main(void){
    int N, x, y;
    cin >> N;
    vector<pair<int, int>> p;
    stack<pair<int, int>> st;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        p.push_back({x, y});
    }
    sort(p.begin(), p.end());
    pair<int, int> maxP;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(st.empty()){
            st.push({p[i].first, p[i].second});
            maxP = st.top();
            continue;
        }
        if(maxP.second <= p[i].second){
            while(st.size() != 1) st.pop();
            ans += (p[i].first - st.top().first) * st.top().second;
            st.pop();
            maxP = p[i];
        }
        st.push({p[i].first, p[i].second});
    }
    pair<int, int> now = st.top();
    st.pop();
    while(!st.empty()){
        while(st.top().second < now.second) st.pop();
        ans += (now.first - st.top().first) * now.second;
        now = st.top();
        st.pop();
    }
    ans += now.second;
    cout << ans;
}