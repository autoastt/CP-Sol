#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
const ll M = 998244353;

unordered_map<ll, ll> dp;

ll pp(ll x){
    if(dp[x]) return dp[x];
    ll k = x/2, l = x%2;
    ll t1 = pp(k) % M;
    dp[x]=(t1*t1*dp[l])%M;
    return dp[x];
}

void solve(ll x) {
    if(x == 1){
        cout << 1;
        return;
    }
    ll k = x%3;
    ll a = x/3;
    ll b = 1;
    if(k == 1) a--, b = 4;
    else if(k == 2) b = 2;
    ll ans = pp(a);
    ans %= M;
    cout << (ans*b)%M;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 9;
    while(t--) {
        ll x;
        cin >> x;
        solve(x);
    }
}