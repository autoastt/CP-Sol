#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    vector<pair<int,char>> v[2];
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B'){
            if(v[0].empty()) continue;
            v[0].pop_back();
        }
        else if(s[i] == 'b'){
            if(v[1].empty()) continue;
            v[1].pop_back();
        }
        else if(s[i] >= 'a' && s[i] <= 'z') v[1].push_back({i, s[i]});
        else v[0].push_back({i, s[i]});
    }
    int i = 0, j = 0;
    while(i < v[0].size() && j < v[1].size()){
        if(v[0][i].first < v[1][j].first) cout << v[0][i++].second;
        else cout << v[1][j++].second;
    }
    while(i < v[0].size()) cout << v[0][i++].second;
    while(j < v[1].size()) cout << v[1][j++].second;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}