#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll x, k = 0;
    string s;
    cin >> s >> x;
    ll n = s.size();
    deque<pair<char,int>> dq;
    vector<int> rem;
    set<int> st;
    for(int i = 0; i < n; i++){
        while(!dq.empty() && dq.back().first > s[i]){
            rem.push_back(dq.back().second);
            dq.pop_back();
        }
        dq.push_back({s[i], i});
    }
    while(!dq.empty()){
        rem.push_back(dq.back().second);
        dq.pop_back();
    }
    for(int i = n; i > 0; i--){
        if(x - i > 0) x -= i, k++;
        else break;
    }
    for(auto i : rem){
        if(!k) break;
        st.insert(i);
        k--;
    }
    for(int i = 0; i < n; i++){
        if(st.count(i)) continue;
        if(x == 1){
            cout << s[i];
            return;
        }
        x--;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}