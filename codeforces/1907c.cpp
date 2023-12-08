#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, mx = 0;
    string s;
    unordered_map<char, int> mp;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }
    for(auto [c, i] : mp) mx = max(mx, i);
    if(mx > n/2) cout << mx - (n - mx) << "\n";
    else cout << n%2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}