#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 998244353;
const int N = 2e5+5;
ll fact[N];
void solve() {
    ll cnt = 0, ans1 = 0, ans2 = 1;
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]) cnt++;
        else {
            if(cnt > 0) ans2 = (ans2 * (cnt+1)) % M, ans1 += cnt, cnt = 0;
        }
    }
    if(cnt > 0) ans2 = (ans2 * (cnt+1)) % M, ans1 += cnt, cnt = 0;
    ans2 = (ans2 * fact[ans1]) % M;
    // for(int i = 1; i <= cnt+1; i++) ans = (ans * i) % M;
    cout << ans1 << " " << (ans2 < 0 ? ans2 + M : ans2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (i*fact[i-1]) % M;
        if(fact[i] < 0) fact[i] += M;
    }
    while(t--) {
        solve();
    }
}