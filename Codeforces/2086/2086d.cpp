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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

const bool CASES = true;
const int N = 5e5 + 5;
const int M = 998244353;
const int INF = 2e9;
const ll LLINF = 1e18;

ll f[N];

void solve() {
    vll a;
    ll ans = 0, n = 0;
    rep (26) {
        int x;
        cin >> x;
        if (!x) continue;
        a.pb(x);
        n += x;
    }
    auto fpow = [&](ll x, ll k) {
        ll ret = 1;
        while (k) {
            if (k & 1) ret = ret * x % M;
            x = x * x % M;
            k >>= 1;
        }
        return ret;
    };
    auto inv = [&](ll x) {
        return fpow(x, M - 2) % M;
    };
    vll dp(n + 1);
    dp[0] = 1;
    rep (i, sz(a)) {
        rrep (j, n + 1) {
            if (j - a[i] >= 0) dp[j] = (dp[j] + dp[j - a[i]]) % M;
        }
    }
    ll x = f[n / 2] * f[(n + 1) / 2] % M;
    for (auto i : a) x = x * inv(f[i]) % M;
    cout << dp[n / 2] * x % M << NL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    f[0] = f[1] = 1;
    rep (i, 2, N - 1) f[i] = f[i - 1] * i % M;
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
