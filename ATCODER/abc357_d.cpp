#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
const bool TESTCASE = false;
const int N = 2e5 + 5;
const int M = 998244353;
const int INF = 2e9;
const ll LLINF = 1e18;

ll pmod(ll p, ll n) {
    p %= M;
    if(n == 0) return 1ll;
    if(n == 1) return p;
    ll x = pmod(p, n/2) % M;
    if(n % 2) return x * x % M * p % M;
    return x * x % M;
}

void solve() {
    ll n;
    cin >> n;
    ll d = 0, tmp = n;
    while(tmp) {
        tmp /= 10;
        d++;
    }
    // [10^(d*n)-1] * [(10^d-1)^(M-2)] * n
    ll ans = n % M;
    ll p = pmod(10, d);
    if(p < 0) p += M;
    ans = ans * (pmod(p, n) - 1) % M;
    if(ans < 0) ans += M;
    ans = ans * pmod(p - 1, M - 2) % M;
    if(ans < 0) ans += M;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t(1);
    if(TESTCASE) cin >> t;
    while(t--) {
        solve();
    }
}

