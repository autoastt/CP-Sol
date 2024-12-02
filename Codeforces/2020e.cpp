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
#define rrep0(a) for (int i = (a) - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = (a) - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'

const bool CASES = true;
const int N = 10;
const int M = 1e9 + 7;
const ll K = 1e4;
const int INF = 2e9;
const ll LLINF = 1e18;

ll fpow(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % M;
        x = x * x % M;
        y >>= 1;
    }
    return ret;
}

ll inv(ll x) {
    return fpow(x, M - 2);
}

void solve() {
    int n;
    cin >> n;
    vll a(n + 1), p(n + 1);
    rep (n) cin >> a[i];
    rep (n) cin >> p[i];
    ll ans = 0, x = inv(fpow(K, n));
    vll dp(1 << N, 0);
    dp[0] = 1;
    rep (i, n) {
        vll ndp = dp;
        rep (j, 1 << N) {
            ndp[j] = (dp[j ^ a[i]] * p[i] % M + dp[j] * (K - p[i]) % M) % M;
        }
        swap(dp, ndp);
    }
    rep (1 << N) {
        ans = (ans + i * i % M * dp[i] % M * x % M) % M;
    }
    cout << ans << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
