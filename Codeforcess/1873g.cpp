#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    int ans = 0, cntl = 0, cntr = 0, cnt = 0, mn = 1e9;
    bool bb = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A') cnt++;
        else ans+=cnt, mn = min(mn, cnt), cnt = 0;
        if(i > 0 && s[i] == 'B' && s[i-1] == 'B') bb = true;
    }
    ans += cnt;
    mn = min(mn, cnt);
    if(s[0] == 'B' || s[s.size()-1] == 'B' || bb) cout << ans << "\n";
    else{
        if(ans > 0) ans -= mn;
        cout << ans << "\n";
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