#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll p[64];

void solve() {
    ll x;
    cin >> x;
    vector<int> ans;
    int k = 63 - __builtin_clzll(x);
    for(int i = 0; i < k; i++){
        if(x & p[i]){
            ans.push_back(1e9);
        }
        ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    p[0] = 1;
    for(int i = 1; i < 64; i++) p[i] = p[i-1]*2;
    while(t--) {
        solve();
    }
}