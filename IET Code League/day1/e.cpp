#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

void solve() {
    int ans = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '6') ans++;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}