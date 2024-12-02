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
#define rrep0(a) for (int i = a; i > 0; i--)
#define rrep1(i, a) for (int i = a; i > 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)

const bool CASES = false;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll dp[N], a[N], b[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pll> v, x;
    rep (n) cin >> a[i];
    rep (n) cin >> b[i], v.pb({a[i] - b[i], a[i]});
    sort(all(v));
    rep (n) {
        if (sz(x) && (v[i].first == x.back().first || v[i].second >= x.back().second)) continue;
        x.pb(v[i]);
    }
    reverse(all(x));
    int j = 0;
    rep (N) {
        if (i >= x[j].second) j++;
        if (j > sz(x)) break;
        if (!j) continue;
        auto [d, aj] = x[j-1];
        ll k = (i - aj) / d + 1;
        dp[i] = 2 * k + (i >= k * d ? dp[i - k * d] : 0);
    }
    ll ans = 0;
    rep (m) {
        int c; cin >> c;
        if (c >= x.back().second) {
            ll k = (c - x.back().second) / x.back().first + 1;
            ans += 2 * k;
            c -= k * x.back().first;
        }
        if (c > 0) ans += dp[c];
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
