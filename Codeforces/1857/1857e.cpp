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

const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

ll dp[N], rdp[N];

void solve() {
    int n;
    cin >> n;
    vll a(n);
    vector<pll> v;
    fill_n(dp, N, 0);
    fill_n(rdp, N, 0);
    rep (i, n) cin >> a[i], v.pb({a[i], i});
    sort(all(v));
    rep (i, 1, n-1) dp[i] = dp[i-1] + i * (v[i].first - v[i-1].first);
    rrep (i, n-2, 0) rdp[i] = rdp[i+1] + (n - i - 1) * (v[i+1].first - v[i].first);
    vector<pll> ans;
    rep (i, n) ans.pb({v[i].second, dp[i] + rdp[i] + n});
    sort(all(ans));
    for (auto [i, x] : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
