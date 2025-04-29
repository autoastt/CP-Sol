#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll po(ll p, ll x) {
    ll ret = 1;
    while (x) {
        if (x & 1) ret = (ret * p) % M;
        p = p * p % M;
        x /= 2;
    }
    return ret;
}
void solve() {
    ll l, r, k, ans = 0;
    cin >> l >> r >> k;
    if (k == 1) ans = 1ll * (po(10, r) - po(10, l)) % M;
    else if (k == 2) ans = 1ll * (po(5, r) - po(5, l)) % M;
    else if (k == 3) ans = 1ll * (po(4, r) - po(4, l)) % M;
    else if (k == 4) ans = 1ll * (po(3, r) - po(3, l)) % M;
    else if (k < 10) ans = 1ll * (po(2, r) - po(2, l)) % M;
    if (ans < 0) ans += M;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
