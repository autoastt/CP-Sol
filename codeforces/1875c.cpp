#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<ll> s;
void solve() {
    ll n,m, ans = 0;
    cin >> n >> m;
    n %= m;
    if(!n){cout << "0\n"; return;}
    ll g = gcd(n,m), tmp = m/g;
    if(s.count(tmp) == 0){cout << "-1\n"; return;}
    ans = n;
    while(n){
        n = (n*2) % m;
        ans += n;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    ll k = 1;
    s.insert(1);
    for(int i = 0; i < 30; i++) s.insert(k = k*2);
    while(t--) {
        solve();
    }
}