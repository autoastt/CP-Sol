#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define GET_MACRO(_1, _2, _3, _4, NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep3, rrep2, rrep1, rrep0)(__VA_ARGS__)
#define rep0(a) for (int i = 0; i < a; i++)
#define rep1(i, a) for (int i = 0; i < a; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define rep3(i, a, b, c) for (int i = a; i <= b; i += c)
#define rrep0(a) for (int i = a - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = a - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'

const bool CASES = false;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll f[N];

ll fastpow(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = (ret * x) % M;
        x = (x * x) % M;
        n >>= 1;
    }
    return ret;
}

ll inv(int x) {
    return fastpow(x, M - 2) % M;
}

ll ncr(int n, int r) {
    return (f[n] * inv(f[r]) % M) * inv(f[n - r]) % M;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vll dp(n + 1, 0);
    map<int, ll> s;
    rep (n) {
        int l, r;
        cin >> l >> r;
        s[l]++;
        s[r + 1]--;
    }
    ll now = 0, l = -INF, ans = 0;
    for (auto [i, x] : s) {
        if (l != -INF) dp[now] = (dp[now] + i - l) % M;
        now += x;
        l = i;
    }
    rep (i, k, n) ans = (ans + ncr(i, k) * dp[i]) % M;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    f[0] = 1;
    rep (i, 1, N) f[i] = i * f[i - 1] % M;
    while (t--) {
        solve();
    }
}
