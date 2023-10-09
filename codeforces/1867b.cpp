#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

void solve() {
    int n, cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    bool odd = false;
    for(int i = 0, j = n-i-1; i <= j; i++, j--){
        // cout << i << " " << j << "\n";
        if(i == j) odd = true;
        else if(s[i] != s[j]) cnt++;
    }
    // cout << cnt << ' ' << odd << "\n";
    for(int i = 0; i < cnt; i++) cout << 0;
    for(int i = cnt; i <= n-cnt; i++) {
        if(i%2 != cnt%2){
            if(odd) cout << 1;
            else cout << 0;
        }
        else cout << 1;
    }
    for(int i = n-cnt+1; i <= n; i++) cout << 0;
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